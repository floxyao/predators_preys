#ifndef RANDOM_H
#define RANDOM_H

int getRandom(int lo, int hi);
int getRandom(int lo, int hi){
    int randomNum=rand()%hi+lo;
    return randomNum;
}

#endif // RANDOM_H
