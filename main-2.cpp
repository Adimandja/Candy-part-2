/* Program name: main.cpp
 * Author: Adolphe Dimandja
 * Date last updated: 7/28/2024
 * Purpose: Main program to allow users to create multiple bags of candy with unique flavor and color combinations, ensuring no duplicates within each bag.
 */

#include <iostream>
#include "candy.h"

bool isUniqueCombination(const Candy** candies, int size, flavorType flavor, colorType color) {
    for (int i = 0; i < size; ++i) {
        if (candies[i]->getFlavor() == flavor && candies[i]->getColor() == color) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "=========================================================================================\n";
    std::cout << "                              Welcome to The Cavity Factory!\n";
    std::cout << "=========================================================================================\n";
    std::cout << "\n- We allow our beloved Candy Connoisseurs (yes, that'd be you) to build their own candy!\n";
    std::cout << "There's only one catch: To ensure that our customers explore their palate,\n";
    std::cout << "we only allow unique candy to be ordered in each bag. Don't think of it as a limitation, but as an EXPERIENCE!\n\n";

    int numBags;
    std::cout << "How many bags of candy would you like to order? (range: 1-10): ";
    std::cin >> numBags;

    int bagCapacity = 5; // Assuming each bag can hold up to 5 candies
    Candy*** bags = new Candy**[numBags];
    int* bagSizes = new int[numBags];

    for (int i = 0; i < numBags; ++i) {
        bags[i] = new Candy*[bagCapacity];
        bagSizes[i] = 0;

        std::cout << "\nFilling bag #" << (i + 1) << ":\n";
        int numCandies;
        std::cout << "How many candies will be in this bag? (max " << bagCapacity << "): ";
        std::cin >> numCandies;

        for (int j = 0; j < numCandies; ++j) {
            int flavorChoice, colorChoice;
            flavorType flavor;
            colorType color;

            do {
                std::cout << "Choose a flavor for candy #" << (j + 1) << ":\n";
                std::cout << "[1] Cotton Candy\n";
                std::cout << "[2] Watermelon Burst\n";
                std::cout << "[3] Papaya Bliss\n";
                std::cout << "[4] Citrus Splash\n";
                std::cout << "[5] Cola\n";
                std::cin >> flavorChoice;
                flavor = static_cast<flavorType>(flavorChoice - 1);

                std::cout << "Choose a color for your candy:\n";
                std::cout << "[1] Scarlet Blaze\n";
                std::cout << "[2] Azure Sky\n";
                std::cout << "[3] Emerald Mist\n";
                std::cout << "[4] Goldenrod Glow\n";
                std::cout << "[5] Amethyst Haze\n";
                std::cin >> colorChoice;
                color = static_cast<colorType>(colorChoice - 1);

                if (isUniqueCombination(bags[i], bagSizes[i], flavor, color)) {
                    bags[i][bagSizes[i]++] = new Candy(flavor, color);
                    std::cout << "Marvelous! Your candy was added to the order.\n";
                    break;
                } else {
                    std::cout << "Duplicate candy! Please choose a different combination.\n";
                }
            } while (true);
        }

        std::cout << "How many more bags with the same candy combination? ";
        int copyCount;
        std::cin >> copyCount;

        if (copyCount + i + 1 > numBags) {
            std::cout << "Cannot copy to that many bags. Only " << (numBags - i - 1) << " remaining.\n";
            copyCount = numBags - i - 1;
        }

        for (int j = 0; j < copyCount; ++j) {
            bags[i + j + 1] = new Candy*[bagCapacity];
            bagSizes[i + j + 1] = bagSizes[i];
            for (int k = 0; k < bagSizes[i]; ++k) {
                bags[i + j + 1][k] = new Candy(*bags[i][k]);
            }
        }

        i += copyCount;
    }

    std::cout << "\nYour order:\n";
    for (int i = 0; i < numBags; ++i) {
        std::cout << "Bag #" << (i + 1) << ":\n";
        for (int j = 0; j < bagSizes[i]; ++j) {
            std::cout << "#" << (j + 1) << " " << bags[i][j]->colorToString() << " " << bags[i][j]->flavorToString() << "\n";
        }
    }

    for (int i = 0; i < numBags; ++i) {
        for (int j = 0; j < bagSizes[i]; ++j) {
            delete bags[i][j];
        }
        delete[] bags[i];
    }
    delete[] bags;
    delete[] bagSizes;

    std::cout << "Thank you for choosing The Cavity Factory, where tooth decay is our priority!\n";

    return 0;
}
