#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(0);
	ofNoFill();
	ofSetLineWidth(2);

	this->frame_number = 0;
}

//--------------------------------------------------------------
void ofApp::update() {

	this->frame_number += 1;
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofColor color;
	for (int k = 0; k < 60; k++) {

		ofRotate(6);

		vector<glm::vec2> vertices;
		for (int i = 0; i < 30; i++) {

			auto radius = k % 2 == 0 ? ofMap(sin((this->frame_number + i) * 0.314 * 0.1), -1, 1, 100, 300) : ofMap(sin((this->frame_number + i) * 0.314 * 0.35), -1, 1, 300, 200);
			auto deg = (this->frame_number + i) * 3;
			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			vertices.push_back(location);
		}

		ofBeginShape();
		ofVertices(vertices);
		ofEndShape();
	}

	/*
	int start = 60;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}