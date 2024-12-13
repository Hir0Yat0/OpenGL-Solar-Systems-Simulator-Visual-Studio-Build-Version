#ifndef SCALES_HPP
#define SCALES_HPP

namespace Scales {
    
    constexpr float distanceFromSunScale = 1.0f / 1.0e+6 * 5.0f;
    constexpr float diameterScale = 1.0f / 1.0e+3;

    constexpr float starSunDiameterKM = 1391400.0f;
    constexpr float planetSunDiameterKM = 1391400.0f;
    constexpr float planetMercuryDiameterKM = 4879.0f;
    constexpr float planetVenusDiameterKM = 12104.0f;
    constexpr float planetEarthDiameterKM = 12756.0f;
    constexpr float planetMarsDiameterKM = 6792.0f;
    constexpr float planetJupiterDiameterKM = 142984.0f;
    constexpr float planetSaturnDiameterKM = 120536.0f;
    constexpr float planetUranusDiameterKM = 51118.0f;
    constexpr float planetNeptuneDiameterKM = 49528.0f;
    constexpr float planetPlutoDiameterKM = 2376.6f;

    constexpr float starSunDiameterScaledKM = starSunDiameterKM * diameterScale ;
    constexpr float planetSunDiameterScaledKM = planetSunDiameterKM * diameterScale ;
    constexpr float planetMercuryDiameterScaledKM = planetMercuryDiameterKM * diameterScale;
    constexpr float planetVenusDiameterScaledKM = planetVenusDiameterKM * diameterScale;
    constexpr float planetEarthDiameterScaledKM = planetEarthDiameterKM  * diameterScale;
    constexpr float planetMarsDiameterScaledKM = planetMarsDiameterKM * diameterScale;
    constexpr float planetJupiterDiameterScaledKM = planetJupiterDiameterKM * diameterScale;
    constexpr float planetSaturnDiameterScaledKM = planetSaturnDiameterKM * diameterScale;
    constexpr float planetUranusDiameterScaledKM = planetUranusDiameterKM * diameterScale;
    constexpr float planetNeptuneDiameterScaledKM = planetNeptuneDiameterKM * diameterScale;
    constexpr float planetPlutoDiameterScaledKM = planetPlutoDiameterKM * diameterScale;

    constexpr float startSunDistanceFromSunKM = 1.0f;
    constexpr float planetSunDistanceFromSunKM = 1.0f;
    constexpr float planetMercuryDistanceFromSunKM = 5.79e+7f;
    constexpr float planetVenusDistanceFromSunKM = 1.082e+8f;
    constexpr float planetEarthDistanceFromSunKM = 1.4960e+8f;
    constexpr float planetMarsDistanceFromSunKM = 2.2790e+8f;
    constexpr float planetJupiterDistanceFromSunKM = 7.7860e+8f;
    constexpr float planetSaturnDistanceFromSunKM = 1.43350e+9f;
    constexpr float planetUranusDistanceFromSunKM = 2.87250e+9f;
    constexpr float planetNeptuneDistanceFromSunKM = 4.49510e+9f;  
    constexpr float planetPlutoDistanceFromSunKM = 5.9e+9f;

    constexpr float startSunDistanceFromSunScaledKM = startSunDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetSunDistanceFromSunScaledKM = planetSunDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetMercuryDistanceFromSunScaledKM = planetMercuryDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetVenusDistanceFromSunScaledKM = planetVenusDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetEarthDistanceFromSunScaledKM = planetEarthDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetMarsDistanceFromSunScaledKM = planetMarsDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetJupiterDistanceFromSunScaledKM = planetJupiterDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetSaturnDistanceFromSunScaledKM = planetSaturnDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetUranusDistanceFromSunScaledKM = planetUranusDistanceFromSunKM * distanceFromSunScale;
    constexpr float planetNeptuneDistanceFromSunScaledKM = planetNeptuneDistanceFromSunKM * distanceFromSunScale;  
    constexpr float planetPlutoDistanceFromSunScaledKM = planetPlutoDistanceFromSunKM * distanceFromSunScale;

    constexpr float planetDistanceLinearOffsetKM = planetSunDiameterScaledKM * 1.0f;
    constexpr float planetDistanceLinearKM = planetJupiterDiameterScaledKM + 100.0f;
    constexpr float gravityScale = 1000.0f;

}; // namespace Scales


#endif // SCALES_HPP
