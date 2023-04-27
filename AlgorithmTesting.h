#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "BruteForceSolution.h"
#include "MapSolution.h"
#include "PSTSolution.h"
#include "Rectangle.h"

struct AlgorithmTesting {
    std::vector<ISolutional*> solutions;
    BruteForceSolution b;
    MapSolution m;
    PSTSolution p;
    int repeatsForAverage = 3;

    AlgorithmTesting() {
        solutions.push_back(&b);
        solutions.push_back(&m);
        solutions.push_back(&p);
    }

    void measureSpeed(std::ofstream& file, std::vector<Rectangle>& rectangles, const std::vector<Point>& points) {
        float buildTime = 0;
        float queriesTime = 0;

        for (auto &i : solutions) {
            for (int repeat = 0; repeat < repeatsForAverage; ++repeat) {
                auto start = std::chrono::high_resolution_clock::now();
                i->build(&rectangles);
                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration<float> duration = end - start;
                buildTime += std::chrono::duration_cast<std::chrono::microseconds>(duration).count();

                start = std::chrono::high_resolution_clock::now();
                i->queries(points);
                end = std::chrono::high_resolution_clock::now();

                duration = end - start;
                queriesTime += std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            }

            file << buildTime / repeatsForAverage << " " << queriesTime / repeatsForAverage << " ";
            std::cout << buildTime / repeatsForAverage << "ms " << queriesTime / repeatsForAverage << "ms ";

            buildTime = 0;
            queriesTime = 0;
        }
        file << "\n";
        std::cout << std::endl;
    }

    static std::vector<Rectangle> generateRectangles(const int & numberOfPoints) {
        std::vector<Rectangle> rectangles;
        for (int i = 0; i < numberOfPoints; ++i) {
            rectangles.emplace_back(10 * i, 10 * i, 10 * (2 * numberOfPoints - i), 10 * (2 * numberOfPoints));
        }
        return rectangles;
    }

    static std::vector<Point> generatePoints(const int &numberOfPoints) {
        std::vector<Point> points;
        std::mt19937 mt_engine;

        auto clock = std::chrono::system_clock();
        auto now = clock.now();
        auto duration_since_epoch = now.time_since_epoch();
        long long nanoseconds_since_epoch = std::chrono::duration_cast<std::chrono::nanoseconds>(duration_since_epoch).count();
        mt_engine.seed(nanoseconds_since_epoch);

        std::uniform_int_distribution<int> point_x(0, numberOfPoints);
        std::uniform_int_distribution<int> point_y(0, numberOfPoints);

        for (int i = 0; i < numberOfPoints; ++i) {
            points.emplace_back(point_x(mt_engine), point_y(mt_engine));
        }

        return points;
    }
};