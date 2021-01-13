#include <opencv2/core/core.hpp>
// including the dense multi-dimensional array Mat and
// basic functions used by  all other modules.

// highgui - an easy-to-use interface to video
// capturing, image and video codecs, as well
// as simple UI capabilities.
#include <opencv2/highgui/highgui.hpp>

// imgproc - an image processing module that
// includes linear and non-linear image filtering,
// geometrical image transformations (resize, affine
// and perspective warping, generic table-based
// remapping) color space conversion, histograms,
// and so on.
#include <opencv2/imgproc/imgproc.hpp>

// The stdio.h header defines three variable types,
// several macros, and various functions for performing
// input and output.
#include <stdio.h>
#include <iostream>

// Namespace where all the C++ OpenCV functionality resides
using namespace cv;

using namespace std;

// We can also use 'namespace std' if need be.

int main() // Main function
{
    // read the image data in the file "MyPic.JPG" and
    // store it in 'img'
    Mat image = imread("bat.jpg", CV_LOAD_IMAGE_UNCHANGED);

    // Mat object is a basic image container.
    // imread: first argument denotes the image to be loaded
    // the second arguments specifies the image format.
    // CV_LOAD_IMAGE_UNCHANGED (<0) loads the image as is
    // CV_LOAD_IMAGE_GRAYSCALE ( 0) loads the image as an
    //                         intensity one
    // CV_LOAD_IMAGE_COLOR (>0) loads the image in the
    //                          BGR format
    // If the second argument is not specified, it is
    // implied CV_LOAD_IMAGE_COLOR

    // Check for no data
    if (! image.data )
    {
        cout << "Could not open or find the image.\n";
        return -1; // unsuccessful
    }

    // Function to blur the image
    // first argument: input source
    // second argument: output source
    // third argument: blurring kernel size
    blur(image,image,Size(10,10));

    namedWindow( "bat", CV_WINDOW_AUTOSIZE );

    // Displays an image in the specified window.
    // first argument: name of the window
    // second argument: image to be shown(Mat object)
    imshow( "bat", image );

    waitKey(0); // Wait infinite time for a keypress

    return 0; // Return from the main function
}
