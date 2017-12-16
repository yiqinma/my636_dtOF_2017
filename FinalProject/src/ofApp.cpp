
//updated
#include "ofApp.h"

using namespace ofxCv;
using namespace cv;


void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetFrameRate(60);
    loadCameras();
    start = false;
    // initialize connection
    for (std::size_t i = 0; i < NUM_CAMERAS; i++)
    {
        IPCameraDef& cam = getNextCamera();
        
        auto grabber = std::make_shared<Video::IPVideoGrabber>();
        
        if (cam.getAuthType() == IPCameraDef::AuthType::COOKIE)
        {
            // Depending on the system, the cookie name may need to be changed.
            grabber->setCookie("user", cam.getUsername());
            grabber->setCookie("password", cam.getPassword());
        }
        else if (!cam.getUsername().empty() || !cam.getPassword().empty())
        {
            grabber->setUsername(cam.getUsername());
            grabber->setPassword(cam.getPassword());
        }
        
        grabber->setCameraName(cam.getName());
        grabber->setURI(cam.getURL());
        grabber->connect(); // connect immediately
        
        // if desired, set up a video resize listener
        ofAddListener(grabber->videoResized, this, &ofApp::videoResized);
        
        grabbers.push_back(grabber);
        
    }
    //    finder.setup("haar_cascades/haarcascade_frontalface_default.xml");
    //
    //    finder.setPreset(ObjectFinder::Preset::Fast);
    count = 1;
     cam.setup(640, 480);
}


IPCameraDef& ofApp::getNextCamera()
{
    nextCamera = (nextCamera + 1) % ipcams.size();
    return ipcams[nextCamera];
}


void ofApp::loadCameras()
{
    
    // all of these cameras were found using this google query
    // http://www.google.com/search?q=inurl%3A%22axis-cgi%2Fmjpg%22
    // some of the cameras below may no longer be valid.
    
    // to define a camera with a username / password
    //ipcams.push_back(IPCameraDef("http://148.61.142.228/axis-cgi/mjpg/video.cgi", "username", "password"));
    
    ofLog(OF_LOG_NOTICE, "---------------Loading Streams---------------");
    
    ofxXmlSettings XML;
    
    if (XML.loadFile("streams.xml"))
    {
        XML.pushTag("streams");
        std::string tag = "stream";
        
        std::size_t nCams = static_cast<std::size_t>(XML.getNumTags(tag));
        
        for (std::size_t n = 0; n < nCams; ++n)
        {
            std::string username = XML.getAttribute(tag, "", "", n);
            std::string password = XML.getAttribute(tag, "", "", n);
            
            std::string auth = XML.getAttribute(tag, "auth-type", "NONE", n);
            
            IPCameraDef::AuthType authType = IPCameraDef::AuthType::NONE;
            
            if (auth.compare("NONE") == 0)
            {
                authType = IPCameraDef::AuthType::NONE;
            }
            else if (auth.compare("BASIC") == 0)
            {
                authType = IPCameraDef::AuthType::BASIC;
            }
            else if (auth.compare("COOKIE") == 0)
            {
                authType = IPCameraDef::AuthType::COOKIE;
            }
            
            IPCameraDef def(XML.getAttribute(tag, "name", "", n),
                            XML.getAttribute(tag, "url", "", n),
                            username,
                            password,
                            authType);
            
            
            std::string logMessage = "" + def.getName() +
            " " +  def.getURL() +
            " " + def.getUsername() +
            " " + def.getPassword() +
            " auth: " + std::to_string(static_cast<int>((def.getAuthType())));
            
            ofLogNotice() << logMessage;
            
            ipcams.push_back(def);
            
        }
        
        XML.popTag();
        
    }
    else
    {
        ofLog(OF_LOG_ERROR, "Unable to load streams.xml.");
    }
    
    ofLog(OF_LOG_NOTICE, "-----------Loading Streams Complete----------");
    
    nextCamera = ipcams.size();
}


void ofApp::videoResized(const void* sender, ofResizeEventArgs& arg)
{
    // Find the camera that sent the resize event changed.
    for (std::size_t i = 0; i < NUM_CAMERAS; ++i)
    {
        if (sender == grabbers[i].get())
        {
            std::stringstream ss;
            ss << "videoResized: ";
            ss << "Camera connected to: " << grabbers[i]->getURI() + " ";
            ss << "New DIM = " << arg.width << "/" << arg.height;
            ofLogVerbose("ofApp") << ss.str();
        }
    }
}

// =============================================================================
void ofApp::update()
{
    // update the cameras
    if(count <= grabbers.size()){
        for (std::size_t i = 0; i < grabbers.size(); ++i)
        {
            grabbers[i]->update();
            if (grabbers[i]->isFrameNew())
                finder.update(grabbers[i]->getPixels());
//                    if (grabbers[i]->isFrameNew()){
//                    contourFinder.setMinAreaRadius(minArea);
//                    contourFinder.setMaxAreaRadius(maxArea);
//                    contourFinder.setThreshold(threshold);
//                        contourFinder.findContours(grabbers[i]->getPixels());
//                    contourFinder.setFindHoles(holes);
//                    }
        }
    }else{
        cam.update();
        if(ofRandom(1) < 0.02)
            shapes.push_back(Shape());
        if(cam.isFrameNew()) {
            
            // update face finder / tracker
            finder.update(cam.getPixels());
        }
    }
}

// =============================================================================
void ofApp::draw()
{
    if(start){
        if(count <= grabbers.size()){
            ofBackground(0,255,255);
            
            ofSetHexColor(0xffffff);
            
            int row = 0;
            int col = 0;
            
            int x = 0;
            int y = 0;
            
            int w = ofGetWidth() / NUM_COLS;
            int h = ofGetHeight() / NUM_ROWS;
            
            float totalKbps = 0;
            float totalFPS = 0;
            
            for (std::size_t i = 0; i < grabbers.size(); ++i)
            {
                x = col * w;
                y = row * h;
                
                // draw in a grid
                row = (row + 1) % NUM_ROWS;
                
                if (row == 0)
                {
                    col = (col + 1) % NUM_COLS;
                }
                
                ofPushMatrix();
                ofTranslate(x,y);
                ofSetColor(255,255,255,255);
                grabbers[i]->draw(0,0); // draw the camera
                
                ofEnableAlphaBlending();
                
                //        // draw the info box
                //        ofSetColor(0,80);
                //        ofDrawRectangle(5,5,w-10,h-10);
                
                float kbps = grabbers[i]->getBitRate() / 1000.0f; // kilobits / second, not kibibits / second
                totalKbps+=kbps;
                
                float fps = grabbers[i]->getFrameRate();
                totalFPS+=fps;
                
                std::stringstream ss;
                
                // ofToString formatting available in 0072+
                
                
//                ss << "NAME: " << grabbers[i]->getCameraName() << std::endl;
//                ss << "HOST: " << grabbers[i]->getHost() << std::endl;
//                ss << "" << grabbers[i]->getUsername() << std::endl;
//                ss << " " << grabbers[i]->getPassword() << std::endl;
                
                ofSetColor(255);
                ofDrawBitmapString(ss.str(), 10, 12);
                
                ofDisableAlphaBlending();
                
                ofPopMatrix();
            }
            
            // keep track of some totals
            float avgFPS = totalFPS / NUM_CAMERAS;
            float avgKbps = totalKbps / NUM_CAMERAS;
            
            ofSetColor(255);
            // ofToString formatting available in 0072+
            ofDrawBitmapString("AVG FPS: " + ofToString(avgFPS,2/*,7,' '*/), 10, 30);
            ofDrawBitmapString("AVG Kb/S: " + ofToString(avgKbps,2/*,7,' '*/), 10, 41);
            ofDrawBitmapString("TOT Kb/S: " + ofToString(totalKbps,2/*,7,' '*/), 10, 52);
            ofDisableAlphaBlending();
            
            ofDrawBitmapString("Press Spacebar for next Video", 10, ofGetHeight() - 14);
            
            for(int i = 0; i < finder.size(); i++) {
                
                ofRectangle face = finder.getObjectSmoothed(i);
                // or get unsmoothed tracker: getObject(i)
                
                
                // draw tracking box
                
                float hue = (float)i/finder.size() * 255.f;
                ofSetColor( ofColor::fromHsb(hue,255,255));
                ofNoFill();
                ofDrawRectangle(face);
            }
        }else{
            ofSetColor(255);
            
            cam.draw(0, 0);
            
            
            
            printf("%d\n",finder.size());
            
            for(int i = 0; i < finder.size(); i++) {
                
                ofRectangle face = finder.getObjectSmoothed(i);
                // or get unsmoothed tracker: getObject(i)
                
                
                // draw tracking box
                
                float hue = (float)i/finder.size() * 255.f;
                ofSetColor( ofColor::fromHsb(hue,255,255));
                //ofNoFill();
                ofDrawRectangle(face);
                for(int i = shapes.size() - 1; i >= 0;i--){
                    shapes[i].update(face.x-face.width/2,face.y-face.height/2,face.height);
                    shapes[i].draw();
                }
            }
        }
    }else{
        ofBackground(0);
        ofPushMatrix();
        ofTranslate(300, ofGetHeight()/2);
        ofSetColor(255);
        ofDrawBitmapStringHighlight("WE ARE WATCHING YOU", -67,-50);
        ofDrawBitmapStringHighlight("PRESS SPACEBAR TO SEE", -70,50);
        ofPopMatrix();
    }
}

// =============================================================================
void ofApp::keyPressed(int key)
{
    if(start){
        if (key == ' ')
        {
            // initialize connection
            for (std::size_t i = 0; i < NUM_CAMERAS; ++i)
            {
                ofRemoveListener(grabbers[i]->videoResized, this, &ofApp::videoResized);
                auto c = std::make_shared<Video::IPVideoGrabber>();
                IPCameraDef& cam = getNextCamera();
                c->setUsername(cam.getUsername());
                c->setPassword(cam.getPassword());
                Poco::URI uri(cam.getURL());
                c->setURI(uri);
                c->connect();
                
                grabbers[i] = c;
            }
            count ++;
        }
    }else{
        if(key == ' ')
            start = true;
    }
}
