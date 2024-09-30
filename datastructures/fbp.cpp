//implementation of FBP in cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// Function to apply ramp filter
void rampFilter(std::vector<std::vector<double>>& sinogramData) {
    int numViews = sinogramData.size();
    int numDetectors = sinogramData[0].size();

    std::vector<double> rampFilter(numDetectors);
    for (int i = 0; i < numDetectors; i++) {
        rampFilter[i] = i - numDetectors / 2;
    }

    for (int i = 0; i < numViews; i++) {
        for (int j = 0; j < numDetectors; j++) {
            double sum = 0;
            for (int k = 0; k < numDetectors; k++) {
                sum += sinogramData[i][k] * rampFilter[(j + k) % numDetectors];
            }
            sinogramData[i][j] = sum;
        }
    }
}

// Function to apply Hann window
void hannWindow(std::vector<std::vector<double>>& sinogramData) {
    int numViews = sinogramData.size();
    int numDetectors = sinogramData[0].size();

    std::vector<double> hannWindow(numDetectors);
    for (int i = 0; i < numDetectors; i++) {
        hannWindow[i] = 0.5 * (1 - std::cos(2 * M_PI * i / (numDetectors - 1)));
    }

    for (int i = 0; i < numViews; i++) {
        for (int j = 0; j < numDetectors; j++) {
            sinogramData[i][j] *= hannWindow[j];
        }
    }
}

// Function to perform backprojection
void backprojection(std::vector<std::vector<double>>& sinogramData, std::vector<std::vector<double>>& image) {
    int numViews = sinogramData.size();
    int numDetectors = sinogramData[0].size();

    for (int i = 0; i < numViews; i++) {
        for (int j = 0; j < numDetectors; j++) {
            for (int k = 0; k < numDetectors; k++) {
                image[j][k] += sinogramData[i][j] * std::cos(M_PI * (j - numDetectors / 2) / numDetectors);
            }
        }
    }
}

int main() {
    // Load sinogram data
    std::ifstream inputFile("sinogram_data.txt");
    /*
    Note that this code assumes that the sinogram data is stored in a file called "sinogram_data.txt" in the same directory as the executable. The file should contain the sinogram data in the following format:
    1.0 2.0 3.0 ...
    4.0 5.0 6.0 ...
    7.0 8.0 9.0 ...
    10.0 11.0 12.0 ...
    where,
    Each row represents a view, and each column represents a detector. The values are separated by spaces.
    */
    std::vector<std::vector<double>> sinogramData;
    double value;
    while (inputFile >> value) {
        sinogramData.back().push_back(value);
        if (inputFile.peek() == '\n') {
            sinogramData.push_back(std::vector<double>());
        }
    }

    // Apply ramp filter
    rampFilter(sinogramData);

    // Apply Hann window
    hannWindow(sinogramData);

    // Perform backprojection
    std::vector<std::vector<double>> image(sinogramData[0].size(), std::vector<double>(sinogramData[0].size()));
    backprojection(sinogramData, image);

    // Display the reconstructed image
    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[i].size(); j++) {
            std::cout << image[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}