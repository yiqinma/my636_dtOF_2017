Faceless

Yiqin Ma

Nowadays surveillance cameras are everywhere. Although many of us are aware that our footages are being taken by those cameras, we wouldn't realize that's violation of privacy and freedom of information until we see those footages. In this project, I'll add masks to the human figures captured on surveillance camera as a protection of personal data.

I used ofxIpVideoGrabber&ofxXmlSettings addons to grab the live stream surveillance camera footage from the Internet, then used ofxCv&ofxOpenCv to detect human figures on the screen. Then draw shapes on their faces. (In order to show the effect, I also used ofxFaceTracker to do a webcam version)

Addons used:
ofxCv
ofxFaceTracker
ofxIpVideoGrabber
ofxOpenCv
ofxXmlSettings


![image](https://github.com/yiqinma/pictures/blob/master/pic.png)
Reference:http://www.facelessexhibition.net/manu-luksch-autgbr

***Because the videos are live stream, there might not be a face in the screen all the time (and sometimes the face might not be big enough).Therefore, at the end of the sketch, I added a webcam version, so that you can see how the sketch will change when there's a face in the screen.
