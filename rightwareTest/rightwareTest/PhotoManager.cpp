#include "PhotoManager.h"

PhotoManager::PhotoManager()
{
}


PhotoManager::~PhotoManager()
{
	imagesPaths.clear();
}

void PhotoManager::readImageFiles(string path)
{
	ofstream myfile;
	string fullInfo = "";
	fs::path folderPath = path;

	if (fs::is_directory(folderPath)) {
		//Get information of all image files
		for (const auto & entry : fs::directory_iterator(path)) {
			if (entry.path().extension() == ".jpg" || entry.path().extension() == ".png") {
				imagesPaths.push_back(entry.path().string());
				fullInfo += "Name  : " + entry.path().filename().string() + "\n"
					+ getImageInfo(entry.path().string());
			}
		}

		//Print information of images
		cout << fullInfo;

		//Write to text file
		myfile.open("imagesInfo.txt");
		cout << "Saving images information ..." << endl;
		myfile << fullInfo;
		myfile.close();
	}
	else {
		cout << "Path does not exist or is not a directory." << endl;
	}
}

string PhotoManager::getImageInfo(string path)
{
	stringstream info;
	Mat src = imread(path);
	if (src.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); //wait for any key press
		return "";
	}

	info << "Width : " << src.size().width << endl;
	info << "Height: " << src.size().height << endl;
	info << "----------" << endl;

	return info.str();
}

Mat PhotoManager::horizontalCombine(string path1, string path2)
{
	// Load images
	Mat image1 = imread(path1);
	Mat image2 = imread(path2);

	if (!image1.data || !image2.data)	// Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return Mat();
	}

	// Get dimension of final image
	int rows = max(image1.rows, image2.rows);
	int cols = image1.cols + image2.cols;

	// Create a black image
	Mat res(rows, cols, CV_8UC3, Scalar(0, 0, 0));

	// Copy images in correct position
	image1.copyTo(res(Rect(0, 0, image1.cols, image1.rows)));
	image2.copyTo(res(Rect(image1.cols, 0, image2.cols, image2.rows)));

	//Save result
	imwrite("horizontal.jpg", res);

	return res;
}

Mat PhotoManager::verticalCombine(string path1, string path2)
{
	// Load images
	Mat image1 = imread(path1);
	Mat image2 = imread(path2);

	if (!image1.data || !image2.data)	// Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return Mat();
	}

	// Get dimension of final image
	int rows = image1.rows + image2.rows;
	int cols = max(image1.cols, image2.cols);

	// Create a black image
	Mat res(rows, cols, CV_8UC3, Scalar(0, 0, 0));

	// Copy images in correct position
	image1.copyTo(res(Rect(0, 0, image1.cols, image1.rows)));
	image2.copyTo(res(Rect(0, image1.rows, image2.cols, image2.rows)));

	//Save result
	imwrite("vertical.jpg", res);

	return res;
}
