// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(sugerir121TEST, noHaySugerencia121){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };
    jugadas j = {
            jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),
            jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),
            jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),
    };

    pos p = {1,1};
    banderitas b = {pos(0,0)};

    ASSERT_FALSE(sugerirAutomatico121(t, b, j, p));
}

TEST(sugerir121TEST, HaySugerencia121Vertical){
    tablero t = {
            { cMINA,  cVACIA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };
    jugadas j = {
            jugada(pos(0, 2), 1),jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 1),jugada(pos(1, 2), 2),
            jugada(pos(2, 0), 0),jugada(pos(2, 2), 1),
            jugada(pos(3, 0), 1),jugada(pos(3, 1), 2),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),
    };

    pos p = {1,1};
    banderitas b = {pos(0,0)};

    ASSERT_TRUE(sugerirAutomatico121(t, b, j, p));
}

TEST(sugerir121TEST, HaySugerencia121Horizontal){
    tablero t = {
            { cVACIA,  cMINA, cVACIA,  cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cVACIA, cVACIA, cVACIA },
    };
    jugadas j = {
            jugada(pos(0, 4), 1),jugada(pos(1, 3), 1),
            jugada(pos(1, 2), 2),jugada(pos(2, 0), 1),
            jugada(pos(1, 1), 1),jugada(pos(3, 0), 1),
            jugada(pos(3, 1), 1),jugada(pos(4, 1), 1),
            jugada(pos(4, 3), 0),
    };

    pos p = {2,2};
    banderitas b = {pos(0,0)};

    ASSERT_TRUE(sugerirAutomatico121(t, b, j, p));
}

TEST(sugerir121TEST, conBanderita){
    tablero t = {
            {cVACIA, cVACIA, cMINA},
            {cVACIA, cVACIA, cVACIA},
            {cMINA, cVACIA, cVACIA}
    };

    jugadas j = {jugada({0,1}, 1), jugada({1,1}, 2), jugada({2,1}, 1)};
    banderitas b = {pos(1,0)};
    pos p = {0,0};

    ASSERT_TRUE(sugerirAutomatico121(t, b, j, p) && p == pos(1,2));
}