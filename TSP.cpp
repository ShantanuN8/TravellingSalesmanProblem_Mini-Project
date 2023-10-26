#include <iostream>
#include <limits>

using namespace std;

const int MAX = numeric_limits<int>::max();
const int MAX_CITIES = 100; 

int nearestNeighbor(int graph[MAX_CITIES][MAX_CITIES], int n, int initialCity) {
    bool visited[MAX_CITIES] = {false};
    int totalDistance = 0;
    int currentCity = initialCity;
    int minDistance, nearestCity;

    visited[currentCity] = true;

    cout << "Shortest path starting from city " << initialCity << ": " << currentCity << " -> ";

    for (int count = 1; count < n; count++) {
        minDistance = MAX;
        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (!visited[nextCity] && graph[currentCity][nextCity] < minDistance) {
                minDistance = graph[currentCity][nextCity];
                nearestCity = nextCity;
            }
        }
        visited[nearestCity] = true;
        totalDistance += minDistance;
        cout << nearestCity << " -> ";
        currentCity = nearestCity;
    }

    totalDistance += graph[currentCity][initialCity]; // Return to the starting city
    cout << initialCity << endl;

    return totalDistance;
}

int main() {
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    int graph[MAX_CITIES][MAX_CITIES];

    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int initialCity;
    cout << "Enter the initial city: ";
    cin >> initialCity;

    if (initialCity < 0 || initialCity >= n) {
        cout << "Invalid initial city. It should be in the range [0, " << n - 1 << "]." << endl;
        return 1;
    }

    int shortestDistance = nearestNeighbor(graph, n, initialCity);
    cout << "Shortest distance: " << shortestDistance << endl;

    return 0;
}