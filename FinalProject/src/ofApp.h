
#pragma once


#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "IPVideoGrabber.h"
#include "ofxOpenCv.h"    // include ofxOpenCv when using ofxCv
#include "ofxCv.h"
#include "Shape.hpp"
#include "ofxFaceTracker.h"


//#if defined(TARGET_OF_IPHONE) || defined(TARGET_ANDROID) || defined(TARGET_LINUX_ARM)
#define NUM_CAMERAS 1
#define NUM_ROWS 1
#define NUM_COLS 1
//#else
//    #define NUM_CAMERAS 9
//    #define NUM_ROWS 3
//    #define NUM_COLS 3
//#endif


class IPCameraDef
{
public:
    enum AuthType {
        NONE,
        BASIC,
        COOKIE
    };
    
    IPCameraDef()
    {
    }
    
    IPCameraDef(const std::string& url): _url(url)
    {
    }
    
    IPCameraDef(const std::string& name,
                const std::string& url,
                const std::string& username,
                const std::string& password,
                const AuthType authType):
    _name(name),
    _url(url),
    _username(username),
    _password(password),
    _authType(authType)
    {
    }
    
    void setName(const std::string& name) { _name = name; }
    std::string getName() const { return _name; }
    
    void setURL(const std::string& url) { _url = url; }
    std::string getURL() const { return _url; }
    
    void setUsername(const std::string& username) { _username = username; }
    std::string getUsername() const { return _username; }
    
    void setPassword(const std::string& password) { _password = password; }
    std::string getPassword() const { return _password; }
    
    void setAuthType(AuthType authType) { _authType = authType; }
    AuthType getAuthType() const { return _authType; }
    
private:
    std::string _name;
    std::string _url;
    std::string _username;
    std::string _password;
    AuthType _authType = NONE;
};


using namespace ofx;


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    std::vector<std::shared_ptr<Video::IPVideoGrabber>> grabbers;
    
    void loadCameras();
    IPCameraDef& getNextCamera();
    std::vector<IPCameraDef> ipcams; // a list of IPCameras
    std::size_t nextCamera;
    bool start;
    ofVideoGrabber cam;
    ofVec2f position;
    float scale;
    
    vector<Shape> shapes;
    int count;
    
    // This message occurs when the incoming video stream image size changes.
    // This can happen if the IPCamera has a single broadcast state (some cheaper IPCams do this)
    // and that broadcast size is changed by another user.
    void videoResized(const void* sender, ofResizeEventArgs& arg);
    
    ofxCv::ObjectFinder finder;    // our face detector
    
    
    //==========
    ofxFaceTracker tracker;
    int spawnNum = 10;
    bool lastDetected = false;
    bool binit = false;
    
};
