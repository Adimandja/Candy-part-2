/* Program name: candy.cpp
 * Author: Adolphe Dimandja
 * Date last updated: 7/28/2024
 * Purpose: Implementation file for the Candy class, which includes methods for setting and getting flavor and color, and converting enums to strings.
 */

#include "candy.h"

Candy::Candy(flavorType flavor, colorType color) : flavor(flavor), color(color) {}

flavorType Candy::getFlavor() const {
    return flavor;
}

void Candy::setFlavor(flavorType flavor) {
    this->flavor = flavor;
}

colorType Candy::getColor() const {
    return color;
}

void Candy::setColor(colorType color) {
    this->color = color;
}

std::string Candy::flavorToString() const {
    switch (flavor) {
        case COTTON_CANDY: return "Cotton Candy";
        case WATERMELON_BURST: return "Watermelon Burst";
        case PAPAYA_BLISS: return "Papaya Bliss";
        case CITRUS_SPLASH: return "Citrus Splash";
        case COLA: return "Cola";
    }
    return "";
}

std::string Candy::colorToString() const {
    switch (color) {
        case SCARLET_BLAZE: return "Scarlet Blaze";
        case AZURE_SKY: return "Azure Sky";
        case EMERALD_MIST: return "Emerald Mist";
        case GOLDENROD_GLOW: return "Goldenrod Glow";
        case AMETHYST_HAZE: return "Amethyst Haze";
    }
    return "";
}
