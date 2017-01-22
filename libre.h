#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#define NCoef 2
#define DCgain 33250


//Vocal A
int32_t fir1A(int16_t NewSample) {
    double ACoef[NCoef+1] = {
        0.00993181,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
        -1.9717168,
       0.981648614
    };

    static int32_t y[NCoef+1];
   
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir2A(int16_t NewSample) {
    double ACoef[NCoef+1] = {
        0.0300124185,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
        -1.96006384,
      0.990076259
    };

    static int32_t y[NCoef+1];
	 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir3A(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.134252647,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
        -1.84320908,
       0.977461732
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}



//Letra E
int32_t fir1E(int16_t NewSample) {
    double ACoef[NCoef+1] = {
        0.088780529,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.868190369,
      0.956970898
    };

    static int32_t y[NCoef+1];
   
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir2E(int16_t NewSample) {
    double ACoef[NCoef+1] = {
       1.026808964,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
        -0.912292403,
      0.939101367
    };

    static int32_t y[NCoef+1];
	 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir3E(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      1.905512949,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       0.02360157,
      0.881911378
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir4E(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.0022168428,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.9899776078,
      0.9921944506
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir5E(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.0817258692,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.9041275616,
      0.9858534308
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir6E(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.1339426822,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.8379643048,
      0.971906987
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

//Vocal I
int32_t fir1I(int16_t NewSample) {
    double ACoef[NCoef+1] = {
        0.0019544535,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
      -1.9916546422,
     0.9936090957
    };

    static int32_t y[NCoef+1];
   
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir2I(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.0812958345,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.8906111525,
     0.971906987
    };

    static int32_t y[NCoef+1];
	 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir3I(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.1711008576,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.7735023339,
      0.9446031914
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir4I(int16_t NewSample) {
    double ACoef[NCoef+1] = {
     0.0017178454,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
      -1.9897700382,
     0.9914878835
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir5I(int16_t NewSample) {
    double ACoef[NCoef+1] = {
     0.0853306632,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
      -1.8865763238,
      0.971906987
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir6I(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.1711008576,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.7735023339,
      0.9446031914
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

//Vocal O
int32_t fir1O(int16_t NewSample) {
    double ACoef[NCoef+1] = {
        0.0059150498,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
      -1.9827515935,
      0.9886666433
    };

    static int32_t y[NCoef+1];
   
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir2O(int16_t NewSample) {
    double ACoef[NCoef+1] = {
     0.0244148179,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
      -1.9656614406,
     0.9900762585
    };

    static int32_t y[NCoef+1];
	 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir3O(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.1059215158,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.8841547427,
     0.9900762585
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir4O(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.0041181571,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.9845484862,
     0.9886666433
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir5O(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.0163630385,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.97371322,
     0.9900762585
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir6O(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.1059215158,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.8841547427,
     0.9900762585
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

//Vocal U
int32_t fir1U(int16_t NewSample) {
    double ACoef[NCoef+1] = {
       0.0024960143,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
      -1.9882858053,
     0.9907818196
    };

    static int32_t y[NCoef+1];
   
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir2U(int16_t NewSample) {
    double ACoef[NCoef+1] = {
    0.0314480251,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
      -1.9530018028,
     0.9844498278
    };

    static int32_t y[NCoef+1];
	 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir3U(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.0965786155,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.8836723821,
   0.9802509977
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir4U(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.0020900364,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.9886917832,
    0.9907818196
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir5U(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.016352732,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.9680970958,
    0.9844498278
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}

int16_t fir6U(int16_t NewSample) {
    double ACoef[NCoef+1] = {
      0.0965786155,
        0,
        0
    };

    double BCoef[NCoef+1] = {
        1,
       -1.8836723821,
    0.9802509977
    };

    static int32_t y[NCoef+1]; 
    static int16_t x[NCoef+1];
    int n;


    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }


    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0];
}
