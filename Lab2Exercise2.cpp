/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  Purpose: 
 *  
 */
#include <iostream>
#include <cmath>
using namespace std;

// Define a struct for 3D points
struct Point {
    double x, y, z;
};

// Function to calculate the distance between two points
double distanceBetweenPoints(const Point& a, const Point& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dz = b.z - a.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Function to calculate the distance between a point and the origin
double distanceToOrigin(const Point& p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

// Function to add two points
Point addPoints(const Point& a, const Point& b) {
    Point result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

// Function to subtract two points
Point subtractPoints(const Point& a, const Point& b) {
    Point result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

int main() {
    Point pointA, pointB;

    // Input coordinates for two points
    cout << "Enter coordinates for Point A (x y z): ";
    cin >> pointA.x >> pointA.y >> pointA.z;

    cout << "Enter coordinates for Point B (x y z): ";
    cin >> pointB.x >> pointB.y >> pointB.z;

    // Calculate and display the distances
    double distanceBetweenTwoPoints = distanceBetweenPoints(pointA, pointB);
    double distanceToOrigin1 = distanceToOrigin(pointA);
    double distanceToOrigin2 = distanceToOrigin(pointB);

    cout << "Distance between Point A and Point B: " << distanceBetweenTwoPoints << endl;
    cout << "Distance from Point A to the origin: " << distanceToOrigin1 << endl;
    cout << "Distance from Point B to the origin: " << distanceToOrigin2 << endl;

    // Calculate and display the result of adding and subtracting points
    Point sum = addPoints(pointA, pointB);
    Point difference = subtractPoints(pointA, pointB);

    cout << "Sum of Point A and Point B (x y z): (" << sum.x << "," << sum.y << "," << sum.z<<")" << endl;
    cout << "Difference between Point A and Point B (x y z): (" << difference.x<<"," << difference.y << ","  << difference.z<<")"<< endl;

    return 0;
}