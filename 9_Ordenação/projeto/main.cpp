#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &vet, int start, int end){

    if(start >= end)
        return;

    int pivot = vet[start];
    int i = start;
    int j = end;


    while(i <= j){

        while(vet[i] < pivot){
            i++;
        }

        while (vet[j] >  pivot){
            j--;
        }

        if(i <= j){
           std::swap(vet[i], vet[j]);
           i++;
           j--;
        }
    }
    quick_sort(vet, start, j);
    quick_sort(vet, i, end);

}

void merge(vector<int>& vet, int a, int b, int c){
        int i= a;
        int j = b;
        vector<int> vaux;
        vaux.reserve(c - a);

        while((i < b) && (j < c)) //compara as partiçoes
                if(vet[i] < vet[j])
                    vaux.push_back(vet[i++]);
                else
                    vaux.push_back(vet[j++]);

        while(i < b)
            vaux.push_back(vet[i++]);

        while(j < c)
            vaux.push_back(vet[j++]);

        for(int i = 0; i < (int) vaux.size(); i++)
             vet[a + i] = vaux[i];
}

