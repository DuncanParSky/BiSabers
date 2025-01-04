#include "modules/ColorGenerator.hpp"

namespace GaySabers {
    Sombrero::FastColor ColorGenerator::lastColor = Sombrero::FastColor(1.0f, 0.0f, 0.5f); // Start with pink (RGB).

    Sombrero::FastColor ColorGenerator::getNextColor() {
        // Define the bi flag colors in RGB
        static const Sombrero::FastColor biFlagColors[] = {
            Sombrero::FastColor(1.0f, 0.0f, 0.5f), // Pink
            Sombrero::FastColor(0.5f, 0.0f, 0.5f), // Purple
            Sombrero::FastColor(0.0f, 0.0f, 1.0f)  // Blue
        };

        // Number of colors in the flag
        static const int numColors = sizeof(biFlagColors) / sizeof(biFlagColors[0]);

        // Find the current index of the last color
        static int currentIndex = 0;

        // Update to the next color in the sequence
        currentIndex = (currentIndex + 1) % numColors;
        lastColor = biFlagColors[currentIndex];

        return lastColor;
    }
}
