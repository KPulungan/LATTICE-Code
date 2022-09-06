#include "TakeupUtil.h"

#include <math.h>

double lattice::DoubleArmTakeupAngles(double mintakeup, double Larm, double dap, double dpdp) {
    // Derived from Mathematica https://github.com/caltechaiaa/LATTICE_Autonomy/blob/main/ShuttleModeling/statespace%20test.nb
    return acos((1 / (128 * pow(dpdp, 2) * pow(Larm, 2))) * (-Larm * mintakeup * (128 * dap * dpdp + 64 * pow(dpdp, 2) + 32 * dap * mintakeup + 16 * dpdp * mintakeup) + sqrt(pow(Larm, 2) * pow(mintakeup, 2) * pow((128 * dap * dpdp + 64 * pow(dpdp, 2) + 32 * dap * mintakeup + 16 * dpdp * mintakeup), 2) - 256 * pow(dpdp, 2) * pow(Larm, 2) * (-64 * pow(dpdp, 2) * pow(Larm, 2) - 64 * pow(dap, 2) * dpdp * mintakeup - 64 * dap * pow(dpdp, 2) * mintakeup - 64 * dpdp * pow(Larm, 2) * mintakeup - 16 * pow(dap, 2) * pow(mintakeup, 2) - 16 * dap * dpdp * pow(mintakeup, 2) + 16 * pow(dpdp, 2) * pow(mintakeup, 2) - 16 * pow(Larm, 2) * pow(mintakeup, 2) + 8 * dpdp * pow(mintakeup, 3) + pow(mintakeup, 4)))));
}

double lattice::SingleArmTakeupAngle(double mintakeup, double Larm, double dap, double dpdp) {
    // Derived from Mathematica https://github.com/caltechaiaa/LATTICE_Autonomy/blob/main/ShuttleModeling/statespace%20test.nb
    return acos((-(Larm * (16 * pow(dap, 3) + 24 * pow(dap, 2) * dpdp + 40 * dap * pow(dpdp, 2) + 16 * pow(dpdp, 3) - 32 * dap * dpdp * sqrt(pow(dap - Larm, 2)) - 16 * pow(dpdp, 2) * sqrt(pow(dap - Larm, 2)) - 32 * dap * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) - 16 * pow(dpdp, 2) * sqrt(pow(dap + dpdp - Larm, 2)) + 16 * dap * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) + 8 * dpdp * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) - 32 * pow(dap, 2) * Larm - 32 * dap * dpdp * Larm - 8 * pow(dpdp, 2) * Larm + 16 * dap * pow(Larm, 2) + 8 * dpdp * pow(Larm, 2) + 32 * dap * dpdp * mintakeup + 16 * pow(dpdp, 2) * mintakeup - 16 * dap * sqrt(pow(dap - Larm, 2)) * mintakeup - 8 * dpdp * sqrt(pow(dap - Larm, 2)) * mintakeup - 16 * dap * sqrt(pow(dap + dpdp - Larm, 2)) * mintakeup - 8 * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) * mintakeup + 8 * dap * pow(mintakeup, 2) + 4 * dpdp * pow(mintakeup, 2))) + sqrt(pow(Larm, 2) * pow(16 * pow(dap, 3) + 24 * pow(dap, 2) * dpdp + 40 * dap * pow(dpdp, 2) + 16 * pow(dpdp, 3) - 32 * dap * dpdp * sqrt(pow(dap - Larm, 2)) - 16 * pow(dpdp, 2) * sqrt(pow(dap - Larm, 2)) - 32 * dap * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) - 16 * pow(dpdp, 2) * sqrt(pow(dap + dpdp - Larm, 2)) + 16 * dap * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) + 8 * dpdp * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) - 32 * pow(dap, 2) * Larm - 32 * dap * dpdp * Larm - 8 * pow(dpdp, 2) * Larm + 16 * dap * pow(Larm, 2) + 8 * dpdp * pow(Larm, 2) + 32 * dap * dpdp * mintakeup + 16 * pow(dpdp, 2) * mintakeup - 16 * dap * sqrt(pow(dap - Larm, 2)) * mintakeup - 8 * dpdp * sqrt(pow(dap - Larm, 2)) * mintakeup - 16 * dap * sqrt(pow(dap + dpdp - Larm, 2)) * mintakeup - 8 * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) * mintakeup + 8 * dap * pow(mintakeup, 2) + 4 * dpdp * pow(mintakeup, 2), 2) - 16 * pow(dpdp, 2) * pow(Larm, 2) * (32 * pow(dap, 2) * pow(dpdp, 2) + 32 * dap * pow(dpdp, 3) + 32 * pow(dpdp, 4) - 16 * pow(dap, 2) * dpdp * sqrt(pow(dap - Larm, 2)) - 32 * dap * pow(dpdp, 2) * sqrt(pow(dap - Larm, 2)) - 48 * pow(dpdp, 3) * sqrt(pow(dap - Larm, 2)) - 16 * pow(dap, 2) * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) - 32 * pow(dpdp, 3) * sqrt(pow(dap + dpdp - Larm, 2)) + 48 * pow(dpdp, 2) * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) - 16 * pow(dap, 3) * Larm - 24 * pow(dap, 2) * dpdp * Larm - 104 * dap * pow(dpdp, 2) * Larm - 48 * pow(dpdp, 3) * Larm + 64 * dap * dpdp * sqrt(pow(dap - Larm, 2)) * Larm + 48 * pow(dpdp, 2) * sqrt(pow(dap - Larm, 2)) * Larm + 64 * dap * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) * Larm + 16 * pow(dpdp, 2) * sqrt(pow(dap + dpdp - Larm, 2)) * Larm - 16 * dap * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) * Larm - 8 * dpdp * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) * Larm + 32 * pow(dap, 2) * pow(Larm, 2) + 32 * dap * dpdp * pow(Larm, 2) + 36 * pow(dpdp, 2) * pow(Larm, 2) - 16 * dpdp * sqrt(pow(dap - Larm, 2)) * pow(Larm, 2) - 16 * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) * pow(Larm, 2) - 16 * dap * pow(Larm, 3) - 8 * dpdp * pow(Larm, 3) + 32 * pow(dap, 2) * dpdp * mintakeup + 32 * dap * pow(dpdp, 2) * mintakeup + 48 * pow(dpdp, 3) * mintakeup - 8 * pow(dap, 2) * sqrt(pow(dap - Larm, 2)) * mintakeup - 16 * dap * dpdp * sqrt(pow(dap - Larm, 2)) * mintakeup - 56 * pow(dpdp, 2) * sqrt(pow(dap - Larm, 2)) * mintakeup - 8 * pow(dap, 2) * sqrt(pow(dap + dpdp - Larm, 2)) * mintakeup - 48 * pow(dpdp, 2) * sqrt(pow(dap + dpdp - Larm, 2)) * mintakeup + 48 * dpdp * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) * mintakeup - 96 * dap * dpdp * Larm * mintakeup - 48 * pow(dpdp, 2) * Larm * mintakeup + 32 * dap * sqrt(pow(dap - Larm, 2)) * Larm * mintakeup + 24 * dpdp * sqrt(pow(dap - Larm, 2)) * Larm * mintakeup + 32 * dap * sqrt(pow(dap + dpdp - Larm, 2)) * Larm * mintakeup + 8 * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) * Larm * mintakeup + 32 * dpdp * pow(Larm, 2) * mintakeup - 8 * sqrt(pow(dap - Larm, 2)) * pow(Larm, 2) * mintakeup - 8 * sqrt(pow(dap + dpdp - Larm, 2)) * pow(Larm, 2) * mintakeup + 8 * pow(dap, 2) * pow(mintakeup, 2) + 8 * dap * dpdp * pow(mintakeup, 2) + 28 * pow(dpdp, 2) * pow(mintakeup, 2) - 24 * dpdp * sqrt(pow(dap - Larm, 2)) * pow(mintakeup, 2) - 24 * dpdp * sqrt(pow(dap + dpdp - Larm, 2)) * pow(mintakeup, 2) + 12 * sqrt(pow(dap - Larm, 2)) * sqrt(pow(dap + dpdp - Larm, 2)) * pow(mintakeup, 2) - 24 * dap * Larm * pow(mintakeup, 2) - 12 * dpdp * Larm * pow(mintakeup, 2) + 8 * pow(Larm, 2) * pow(mintakeup, 2) + 8 * dpdp * pow(mintakeup, 3) - 4 * sqrt(pow(dap - Larm, 2)) * pow(mintakeup, 3) - 4 * sqrt(pow(dap + dpdp - Larm, 2)) * pow(mintakeup, 3) + pow(mintakeup, 4)))) / (8. * pow(dpdp, 2) * pow(Larm, 2)));
}

double lattice::GetTakeup(double leftArmAngle, double rightArmAngle, double Larm, double dap, double dpdp) {
    // Derived on confluence: https://lattice22.atlassian.net/wiki/spaces/L/pages/43352125/Shuttle+Model#Takeup
    return -2 * dpdp + sqrt(pow(dap, 2) + pow(Larm, 2) - 2 * dap * Larm * cos(leftArmAngle)) + sqrt(pow(dap + dpdp, 2) + pow(Larm, 2) - 2 * (dap + dpdp) * Larm * cos(leftArmAngle)) + sqrt(pow(dap, 2) + pow(Larm, 2) - 2 * dap * Larm * cos(rightArmAngle)) + sqrt(pow(dap + dpdp, 2) + pow(Larm, 2) - 2 * (dap + dpdp) * Larm * cos(rightArmAngle));
}

double lattice::GetRelativeArmRates(double doubleArmAngle, double singleArmAngle) {
    // If we approximate the level sets here as linear: https://lattice22.atlassian.net/wiki/spaces/L/pages/43352125/Shuttle+Model#Takeup-Takeaways
    // Then the slope of the level sets can be determined from two points: (doubleArmAngle, doubleArmAngle), (0, singleArmAngle)
    // Thus: (doubleArmAngle - 0)/(doubleArmAngle - singleArmAngle)
    return doubleArmAngle / (doubleArmAngle - singleArmAngle);
}