/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ArrayBigramFreqFunctions.h"

// He interpretado que si el objeto no está usado, coge el constructor por defecto "__" para el bigram
// y la frecuencia a 0.
void readArrayBigramFreq(BigramFreq array[], int dim, int &nElements){
    
    for (int i = 0; i < dim; i++){
        if(array[i].getBigram().getText() != "__" && array[i].getFrequency() != 0){
            nElements++;
        }
    }
}

void printArrayBigramFreq(BigramFreq array[], int nElements){
    std::cout << nElements << std::endl;
    for (int i = 0; i < nElements; i++){
        std::cout << array[i].toString() << std::endl;
    }
}

void swapElementsArrayBigramFreq(BigramFreq array[], int nElements,
        int first, int second){
    
    if(first < nElements && second < nElements && first >= 0 && second >= 1){
        BigramFreq temp = array[first];
        array[first] = array[second];
        array[second] = temp;
    }
}

void sortArrayBigramFreq(BigramFreq array[], int nElements){
    
    int max_index = 0;
    for(int i = 0; i <  nElements - 1; i++){
        max_index = i;
        for(int j = i +1; j < nElements; j++){
           if(array[j].getFrequency() > array[max_index].getFrequency()){
                max_index = j;
            } 
           else if (array[j].getFrequency() == array[max_index].getFrequency()
                && array[j].getBigram().getText() < array[max_index].getBigram().getText()){
                max_index = j;
            }
        }
        swapElementsArrayBigramFreq(array,nElements, i, max_index);
    }
}

void toUpperArrayBigramFreq(BigramFreq array[], int nElements){
    Bigram b;
    for(int i = 0; i < nElements; i++){
        b.at(0) = std::toupper(array[i].getBigram().at(0));
        b.at(1) = std::toupper(array[i].getBigram().at(1));
    
        array[i].setBigram(b);
    }
}
