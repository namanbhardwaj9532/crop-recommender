#include <iostream>
#include <string>

using namespace std;

int getSoilCode(const string& soil) {
    if (soil == "Loamy") return 1;
    if (soil == "Sandy") return 2;
    if (soil == "Clay") return 3;
    if (soil == "Silty") return 4;
    if (soil == "Peaty") return 5;
    return 0;
}

string recommend_crop(int soilCode, float ph, float temp) {
    switch (soilCode) {
        case 1:
            if (ph >= 6.0 && ph <= 7.5 && temp >= 20.0 && temp <= 30.0)
                return "Recommended Crop: Wheat";
            if (ph >= 6.5 && ph <= 7.0 && temp >= 18.0 && temp <= 22.0)
                return "Recommended Crop: Barley";
            if (ph >= 6.0 && ph <= 6.5 && temp >= 25.0 && temp <= 35.0)
                return "Recommended Crop: Sunflower";
            if (ph > 7.5 && temp >= 20.0 && temp <= 30.0)
                return "Recommended Crop: Soybean";
            if (ph >= 5.5 && ph < 6.0 && temp >= 15.0 && temp <= 18.0)
                return "Recommended Crop: Oats";
            break;

        case 2:
            if (ph >= 5.5 && ph <= 7.0 && temp >= 25.0 && temp <= 35.0)
                return "Recommended Crop: Rice";
            if (ph < 5.5 && temp >= 30.0 && temp <= 40.0)
                return "Recommended Crop: Cactus";
            if (ph >= 7.0 && temp >= 28.0 && temp <= 38.0)
                return "Recommended Crop: Melon";
            if (ph >= 6.0 && ph <= 6.5 && temp >= 20.0 && temp <= 30.0)
                return "Recommended Crop: Peas";
            break;

        case 3:
            if (ph >= 6.5 && ph <= 7.5 && temp >= 15.0 && temp <= 25.0)
                return "Recommended Crop: Corn";
            if (ph >= 6.5 && ph <= 7.5 && temp >= 30.0 && temp <= 35.0)
                return "Recommended Crop: Cotton";
            if (ph > 7.5 && temp >= 20.0 && temp <= 30.0)
                return "Recommended Crop: Soybean";
            if (ph >= 5.5 && ph < 6.0 && temp >= 18.0 && temp <= 22.0)
                return "Recommended Crop: Potatoes";
            break;

        case 4:
            if (ph >= 6.0 && ph <= 7.0 && temp >= 18.0 && temp <= 25.0)
                return "Recommended Crop: Tomato";
            if (ph >= 6.2 && ph <= 7.2 && temp >= 15.0 && temp <= 22.0)
                return "Recommended Crop: Broccoli";
            break;

        case 5:
            if (ph >= 5.5 && ph <= 6.5 && temp >= 15.0 && temp <= 20.0)
                return "Recommended Crop: Cabbage";
            if (ph >= 6.0 && ph <= 7.0 && temp >= 16.0 && temp <= 23.0)
                return "Recommended Crop: Broccoli";
            break;

        default:
            return "Unknown soil type.";
    }

    return "No recommendation available for the given conditions.";
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <soil_type> <ph_value> <temperature>" << endl;
        return 1;
    }

    string soil = argv[1];
    float ph = stof(argv[2]);
    float temp = stof(argv[3]);

    int soilCode = getSoilCode(soil);
    string recommendation = recommend_crop(soilCode, ph, temp);

    cout << recommendation << endl;
    return 0;
}
