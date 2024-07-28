/* Program name: candy.h
 * Author: Adolphe Dimandja
 * Date last updated: 7/28/2024
 * Purpose: Header file for the Candy class, which includes the flavorType and colorType enums, and the Candy class declaration.
 */

#ifndef CANDY_H
#define CANDY_H

#include <string>

enum flavorType { COTTON_CANDY, WATERMELON_BURST, PAPAYA_BLISS, CITRUS_SPLASH, COLA };
enum colorType { SCARLET_BLAZE, AZURE_SKY, EMERALD_MIST, GOLDENROD_GLOW, AMETHYST_HAZE };

class Candy {
private:
    flavorType flavor;
    colorType color;

public:
    Candy(flavorType flavor, colorType color);

    flavorType getFlavor() const;
    void setFlavor(flavorType flavor);

    colorType getColor() const;
    void setColor(colorType color);

    std::string flavorToString() const;
    std::string colorToString() const;
};

#endif // CANDY_H
