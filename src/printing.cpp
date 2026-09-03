#include "printing.h"
#include "grading.h"
#include "utilities.h"
#include <iostream>
#include <iomanip>

void printHeader() {
    std::cout << std::left << std::setw(NAME_WIDTH) << "Name";
    for (int j = 0; j < ASSIGNMENT_COUNT; j++) {
        std::cout << std::right << std::setw(8) << ("A" + std::to_string(j + 1));
    }
    std::cout << std::right << std::setw(10) << "Avg" << std::right << std::setw(8) << "Grade" << "\n";
    std::string totalWidth(NAME_WIDTH + (ASSIGNMENT_COUNT * 8) + 18, '-');
    std::cout << totalWidth << "\n";
}

void printStudentRow(const std::array<std::string, STUDENT_COUNT>& names, const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    std::cout << std::left << std::setw(NAME_WIDTH) << names[studentIndex];
    for (int j = 0; j < ASSIGNMENT_COUNT; j++) {
        std::cout << std::right << std::setw(8) << std::fixed << std::setprecision(1) << scores[studentIndex][j];
    }
    double avg = studentAverage(scores, studentIndex);
    char grade = letterGrade(avg);
    std::cout << std::right << std::setw(10) << std::fixed << std::setprecision(1) << avg 
              << std::right << std::setw(8) << grade;

    if (hasPerfectScore(scores, studentIndex)) {
        std::cout << " *";
    }
    if (isAtRisk(scores, studentIndex)) {
        std::cout << " !";
    }
    std::cout << "\n";
}

void printHistogram(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, const std::array<std::string, STUDENT_COUNT>& names) {
    std::cout << "\n--- Grade Distribution (Histogram) ---\n";
    for (int i = 0; i < STUDENT_COUNT; i++) {
        std::cout << std::left << std::setw(NAME_WIDTH) << names[i] << ": ";
        double avg = studentAverage(scores, i);
        int stars = static_cast<int>(avg / 10);
        for (int s = 0; s < stars; s++) {
            std::cout << "*";
        }
        std::cout << " (" << std::fixed << std::setprecision(1) << avg << ")\n";
    }
}

void printAssignmentSummary(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores) {
    std::cout << "\n--- Assignment Averages ---\n";
    for (int j = 0; j < ASSIGNMENT_COUNT; j++) {
        double avg = assignmentAverage(scores, j);
        std::cout << "Assignment " << (j + 1) << ": " << std::fixed << std::setprecision(2) << avg << "\n";
    }
}

void printRoster(const std::array<std::string, STUDENT_COUNT>& names) {
    std::cout << "\n--- Student Roster ---\n";
    for (int i = 0; i < STUDENT_COUNT; i++) {
        std::cout << (i + 1) << ". " << names[i] << "\n";
    }
}
