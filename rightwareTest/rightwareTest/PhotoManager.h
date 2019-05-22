#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
namespace fs = std::experimental::filesystem;

class PhotoManager
{
private:
	vector<string> imagesPaths;
public:
	PhotoManager();
	~PhotoManager();
	void readImageFiles(string path);
	string getImageInfo(string path);
	Mat horizontalCombine(string path1, string path2);
	Mat verticalCombine(string path1, string path2);
};

