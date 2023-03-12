#include <bits/stdc++.h>

using namespace std;

class Soal{
public:
    void soalMean1(){
        int arr[] = {92,98,83,75,76,77,80,86,37};
        int n = sizeof(arr)/sizeof(arr[0]);
        double sum = 0;
        for(int &i : arr){
            sum += i;
        }
        printf("Jumlah Orang    : %d\n",n);
        printf("Jumlah Nilai    : %.0f\n",sum);
        printf("Hasil Rata-Rata : %.2f\n",sum/n);
    }

    void soalMean2(){
        vector<tuple<int,int,int>> data = 
        {
            {17,30,1},
            {31,44,1},
            {45,58,0},
            {59,72,10},
            {73,86,23},
            {87,100,2},
        };
        int size = data.size();
        double Fi = 0; double frekuensi;
        double FiXi = 0; double nilaiTengah;
        for(auto &d : data){
            frekuensi = get<2>(d);
            //Mencari nilai tengah
            nilaiTengah = ((get<0>(d) + get<1>(d)) / 2);
            Fi += frekuensi;
            FiXi +=  frekuensi * nilaiTengah;
        }
        printf("Jumlah Subjek              : %.2f\n",Fi);
        printf("Jumlah Hasi Kali Fi dan Xi : %.2f\n",FiXi);
        printf("Rata - Rata                : %.2f\n",FiXi/Fi);
    }

    
};      

class SoalBab4{
private:
    vector<double>nilai;
    int size; 
    double mean;
    double variansi;
public:
    SoalBab4(){ 
        this->nilai = {37.83, 78.03, 83.33, 92.98, 69.67, 81.27, 78.46, 
        74.04, 98.88, 83.41, 77.78, 77.70, 73.50, 76.07, 76.12, 78.23, 73.34, 
        71.05, 78.50, 75.21, 71.96, 80.58, 80.83, 86.84, 75.29, 71.42, 70.33, 
        71.42, 82.17, 72.50, 73.96, 83.92, 21.00, 72.29, 76.04, 69.25, 70.33};
        this->size = nilai.size();
        sort(nilai.begin(),nilai.end());
    }

    void soalDeviasiMean(){
        //Mencari nilai rata-ratanya terlebih dahulu
        double sum = 0, mean, deviasi = 0;
        for(auto &n : this->nilai){
            sum += n;
        }
        //hasil rata-rata
        mean = sum / this->size;
        //Mencari deviasi
        for(auto &n : this->nilai){
            deviasi += abs(n - mean);
        }
        deviasi = deviasi / size;
        printf("Jumlah data         : %d\n",size);
        printf("Rata - rata         : %.2f\n",mean);
        printf("Deviasi rata - rata : %.2f\n",deviasi);
        this->mean = mean;
    }

    void soalJangkauan(){
        printf("Nilai Minimal  : %.2f\n",nilai[0]);
        printf("Nilai Maksimal : %.2f\n",nilai[36]);
        printf("Jangkauan      : %.2f\n",nilai[36] - nilai[0]);
    }

    void soalVariansi(){
        double variansi = 0;
        for(auto &n : this->nilai){
            variansi += pow(abs(this->mean - n),2);
        }
        variansi = variansi / (this->size);
        printf("Hasil Variansi : %.2f\n",variansi);
        this->variansi = variansi;
    }

    void soalStandarDeviasi(){
        printf("Standar Deviasi : %.2f\n",sqrt(this->variansi));
    }
};
 


int main(){
    Soal soal;
    soal.soalMean1();
    printf("==============================\n");
    soal.soalMean2(); 
    SoalBab4 soal4 = SoalBab4();
    soal4.soalDeviasiMean();
    // printf("==============================\n");
    soal4.soalJangkauan();
    // printf("==============================\n");
    soal4.soalVariansi();
    // printf("==============================\n");
    soal4.soalStandarDeviasi();
} 
