#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class Car {
public:
    int econsume (int a, int b){
        int econsump=0;
        if(a>0 && a<40) econsump += 5;
        else if (a > 40) econsump += 10;
        else if (a == 0) econsump += 8;
        if (b >= 50) econsump += 8;
        else if (b < 50) econsump += 5;
        return econsump;
    }
    void print(int a, int b, int c, int d, int e){
        cout << "Current status : Car\n" << "Distance : " << a << " km\n" <<  "Speed : " << b << " km/h" << endl;
        cout << "Energy : " << c << "\n" << "Temperature : " << d << " C\n" << "Humidity : " << e << endl;
    }
};

class Airplane {
public:
    int econsume(int a,int b){
        int econsump=0;
        if(a>0 && a<40) econsump += 5;
        else if (a > 40) econsump += 10;
        else if (a == 0) econsump += 8;

        if (b >= 50) econsump += 8;
        else if (b < 50) econsump += 5;
        return econsump;
    }
    int calspeed(int a){
        int s=0;
        if(a>=30 && a<50) s+=200;
        else if (a>=50 && a<70) s += 300;
        else if (a>=70) s+=500;
        return s;
    }
     void print(int a, int b, int c, int d, int e, int f, int g, int h){
        cout << "Current status : Airplane\n" << "Distance : " << a << " km\n" <<  "Speed : " << b << " km/h" << endl;
        cout << "Energy : " << c << "\n" << "Oxygen Level : " << d << "\n" << "Temperature : " << e << " C\n" << "Humidity : " << f << endl;
        cout << "Altitude : " << g << "\n" << "Air Density : " << h << endl;
    }
};

class Submarine {
public:
    int econsume(int a, int b){
        int econsump=0;
        if(a>0 && a<40) econsump += 5;
        else if (a > 40) econsump += 10;
        else if (a == 0) econsump += 8;
        econsump += 30;
        return econsump;
    }
    void print(int a, int b, int c, int d, int e, int f, int g){
        cout << "Current status : Submarine\n" << "Distance : " << a << " km" << endl;
        cout <<"Speed : " << b << " km/h" << endl;
        cout << "Energy : " << c << "\n" << "Oxygen Level : " << d << endl;
        cout<< "Temperature : " << e << " C\n" << "Depth : " << f << " m" << endl;
        cout << "Water Flow : " << g << endl;
    }
    int calspeed (int a){
        int s=20;
        if(a>=30 && a<50) s-=3;
        else if (a>=50 && a<70) s -= 5;
        else if (a>=70) s-=10;
        return s;
    }
};

int S[5],R[3],O[4];
int BM[20000],BE[20000],BO[20000],BS[20000]; // BM : Black box Name, BE: Black box Energy, BO : B Oxygen, BS : B Speed //

vector<char *> gettext(int test){
    char input1[2000] = "[R150T70H30],[X],[S3000T10H5A2000D20],[Y],[R50T30H50],[O80T0D100W100],[R150T30H50]";
    char input2[2000] = "[R700T20H20],[O90T0D100W100],[R1000T20H20],[O90T0D100W100],[R1500T20H20],[X],[O90T0D100W100]";
    char input3[2000] = "[R150T20H30],[S3000T10H5A1000D20],[O30T0D50W100]";
    char input4[2000] = "[R150T20H30],[S3000T10H5A1000D20],[O30T0D50W100],[R150T20H30],[S3000T10H5A1000D20],[O30T0D50W100]";
    char input5[2000] = "[R150T20H30],[O80T0D50W100],[R150T20H60],[O80T0D50W100],[R150T20H30]";
    char input6[2000] = "[R150T20H30],[S3000T10H5A1000D20],[O30T0D50W100],[R3000T70H70]";
    char input7[2000] = "[R150T20H30],[S4000T10H5A4000D20],[O30T0D50W100]";
    char input8[2000] = "[R150T70H30],[S6000T70H70A1000D20],[O30T70D50W100],[R1550T70H60],[S10000T70H70A1000D20]";
    char input9[2000] = "[R150T20H30],[S3000T10H5A1000D20],[O60T0D200W100]";
    char input10[2000] = "[R150T20H30],[O80T0D50W100],[R150T20H60],[Y],[O80T0D50W100],[R150T20H30]";
    char str[2000];

    if(test==1) strcpy(str,input1);
    else if(test==2) strcpy(str,input2);
    else if(test==3) strcpy(str,input3);
    else if(test==4) strcpy(str,input4);
    else if(test==5) strcpy(str,input5);
    else if(test==6) strcpy(str,input6);
    else if(test==7) strcpy(str,input7);
    else if(test==8) strcpy(str,input8);
    else if(test==9) strcpy(str,input9);
    else if(test==10) strcpy(str,input10);

    char *pch;
    const char* delimiter = ",";
    vector<char *> a;
    pch = strtok(str,delimiter);
    while (pch != NULL)
    {
        a.push_back(pch);
        pch = strtok (NULL,delimiter);
    }
    return a;
}

char getinput(char *teststring) {
    string semi;
    const char* delimiter1 = "[]RTH";
    const char* delimiter2 = "[]STHAD";
    const char* delimiter3 = "[]OTDW";

    char* pch1;

    char str1[100];
    strcpy(str1,teststring);
    vector<char *> a1;

    int i=0;
    if(str1[1]=='X') return 'X';
    else if(str1[1]=='Y') return 'Y';
    else if(str1[1]=='R'){
        pch1 = strtok (str1,delimiter1);
        while (pch1 != NULL)
        {
            a1.push_back(pch1);
            semi = pch1;
            R[i] = stoi(semi);
            i++;
            pch1 = strtok(NULL,delimiter1);
        }
        return 'R';
    }
    else if(str1[1]=='S'){
        pch1 = strtok (str1,delimiter2);
        while (pch1 != NULL)
        {
            a1.push_back(pch1);
            semi = pch1;
            S[i] = stoi(semi);
            i++;
            pch1 = strtok(NULL, delimiter2);
        }
        return 'S';
    }
    else if(str1[1]=='O'){
        pch1 = strtok (str1,delimiter3);
        while (pch1 != NULL)
        {
            a1.push_back(pch1);
            semi = pch1;
            O[i] = stoi(semi);
            i++;
            pch1 = strtok (NULL,delimiter3);
        }
        return 'O';
    }
}

void blackbox(int bm,int be, int bo, int bs){
    cout<<"\nBlackbox :"<<endl;
    cout<<"Mode :";
    for(int i=0; i<bm; i++)
    {
        if(i!=bm-1) {
            if(BM[i]==1) cout<<" Car >";
            else if (BM[i]==2) cout<<" Airplane >";
            else if (BM[i]==3) cout<<" Submarine >";
        }
        else{
            if(BM[i]==1) cout<<" Car ";
            else if (BM[i]==2) cout<<" Airplane ";
            else if (BM[i]==3) cout<<" Submarine ";
        }
    }
    cout<<"\n";
    cout<<"Energy Level : ";
    for(int j=0; j<be; j++){
        if(j!=be-1) cout<<BE[j]<<" >";
        else cout<<BE[j];
    }
    cout<<"\n"<<"Oxygen Level : ";
    for(int k=0; k<bo; k++){
        if(k!=bo-1) cout<<BO[k]<<" >";
        else cout<<BO[k];
    }
    cout<<"\n"<<"Speed : ";
    for(int l=0; l<bs; l++){
        if(l!=bs-1) cout<<BS[l]<<" >";
        else cout<<BS[l];
    }
}

string extrab(int test){
    int num = gettext(test).size();
    string ex="|";
    char p;
    for(int a=0; a<num; a++){
        p=getinput(gettext(test)[a]);
        if(p=='R'){
            for(int i=0; i<R[0]/50; i++){
                ex+="=";
            }
        }
        if(p=='S'){
            for(int j=0; j<S[0]/1000; j++){
                ex+="^";
            }
        }
        if(p=='O'){
            for(int k=0; k<O[0]/10; k++){
                ex+="~";
            }
        }
    }
    ex+="|";
    return ex;
}

void printFail(int ch, int j, int graphic, int d, int e, int o, int standard, string temp){
    if(ch==1) printf("Successfully moved to next %d km\n", standard);
    else if (ch==2) printf("Successfully moved to next %d km\n", (j+1)*standard);
    cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;

    printf(" Final Status :\n Distance : %d km\n Energy : %d\n Oxygen Level : %d\n", d,e,o);
    if(e==0) cout<<"\n!FINISHED : Energy failure" << endl;
    else if(o==0) cout<<"\n!FINISHED : Oxygen failure" << endl;
    else cout<<"\n!FINISHED vehicle stop" << endl;
}

int main()
{
    int select;  // select whether extra or normal //
    cout<<"Mode select(1 for EXTRA, 2 for NORMAL) : ";
    cin >> select;
    while(1){
        int testnum; // input of test case//
        int vecnum;  // size of the input string //
        char p;      // get test case input //
        int graphic=0; //need to print extra graphic//
        int ch;        // to choose whether method 1 or 2 //
        int e=1000, d=0, o=100;  // e : Energy, d : Distance, o : Oxygen //
        int bm=0,be=0,bo=0,bs=0; // bm : Black box Name control, be : Energy control, bo : Oxygen control, bs : Speed control //
        int solar=0;             // to control solar //
        int endcondi=1;  // to control printing "!Finished Arrived" since its in the end of the while scope//

    cout<<"PJ1.KJW.2018-14385" <<endl;
    cout<<"Choose the number of the test case (1~10) :";
    cin >> testnum;

    string temp = extrab(testnum);
    vecnum = gettext(testnum).size();
    if(testnum == 0) return 0;
    else cout <<"Test case #"<< testnum <<".\n"<< endl;

    for (int i=0; i<vecnum; i++){

        p=getinput(gettext(testnum)[i]); // to determine Road, Sky, Ocean //

        if(p=='R'){
            if(solar==0 && R[2]<50) e+=200;
            if(e>1000) e=1000;
            o=100;

            Car newc;

            if (i==0){
                newc.print(0,0,e,R[1],R[2]);
                cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                cout << "Next Move? (1,2)" << endl;
                cout << "CP-2018-14385> ";
                cin >> ch;
            }

            int roadLen=R[0]/50;
            int ch2control=0;
            int j;
            for( j=0; j<roadLen; j++) {
                e -= newc.econsume(R[1],R[2]);
                d+=50;
                if(e<=0) e=0;

                graphic++;
                if(j<roadLen-1 || i<vecnum-1){
                     if(e<=0) {
                        printFail(ch, j, graphic, d, e, o, 50,temp);
                        BM[bm]=1, BE[be]=e, BO[bo]=o, BS[bs]=80;
                        bm++,be++,bo++,bs++;
                        blackbox(bm,be,bo,bs);
                        cout<<"\n-----------------------"<<endl;
                        endcondi=0;
                        break;
                     }
                }

                if(ch==1 && (i<vecnum-1 || j<roadLen-1)){
                    printf("Successfully moved to next 50 km\n");
                    newc.print(d,80,e,R[1],R[2]);
                    cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                    if(j<roadLen-1){
                        cout << "Next Move? (1,2)" << endl;
                        cout << "CP-2018-14385>> ";
                        cin >> ch;
                        ch2control++;
                    }
                }
            }

            if(endcondi==0) break;

            if(ch == 2 && ch2control!=j) {
                printf("Successfully moved to next %d km\n", R[0]-ch2control*50);
                if(i!=vecnum-1){
                    newc.print(d, 80, e, R[1], R[2]);
                    cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                }
            }

           BM[bm]=1, BE[be]=e, BO[bo]=o, BS[bs]=80;   //black box update //
           bm++,be++,bo++,bs++;
        }

        else if(p=='S'){
             int aspeed=900; //initialize airplane speed //
             int j,ch2control=0;
             int skyLen=S[0]/1000;

             Airplane newa;

             if(i==0) {
                newa.print(d, 0, e, o, S[1], S[2], S[3], S[4]);
                cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                cout << "Next Move? (1,2)\n" << "CP-2018-14385> ";
                cin >> ch;
             }

             aspeed -= newa.calspeed(S[4]);

             for(j=0; j<skyLen; j++){
                 e-=newa.econsume(S[1],S[2]);
                 d+=1000;
                 o-=S[3]/1000*10;
                 if(o<=0) o=0;
                 if(e<=0) e=0;

                 graphic++;
                 if(j<vecnum-1 || j<skyLen-1){
                     if(e<=0) {
                        printFail(ch, j, graphic, d, e, o, 1000,temp);
                        BM[bm]=2, BE[be]=e, BO[bo]=o, BS[bs]=aspeed;
                        bm++,be++,bo++,bs++;
                        blackbox(bm,be,bo,bs);
                        cout<<"\n-----------------------"<<endl;
                        endcondi=0;
                        break;
                     }
                     if(o<=0) {
                        printFail(ch, j, graphic, d, e, o, 1000,temp);
                        BM[bm]=2, BE[be]=e, BO[bo]=o, BS[bs]=aspeed;
                        bm++,be++,bo++,bs++;
                        blackbox(bm,be,bo,bs);
                        cout<<"\n-----------------------"<<endl;
                        endcondi=0;
                        break;
                     }
                 }
                if(ch==1 && (i<vecnum-1 || j<skyLen-1)){
                    printf("Successfully moved to next 1000 km\n");
                    newa.print(d,aspeed, e, o, S[1], S[2], S[3], S[4]);
                    cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                    if(j<skyLen-1){
                        cout << "Next Move? (1,2)\n" << "CP-2018-14385> ";
                        cin >> ch;
                        ch2control++;
                    }
                }
             }
             if(endcondi==0) break;
             if(ch==2 && ch2control!=j) {
                    printf("Successfully moved to next %d km\n", S[0]-ch2control*1000 );
                    if(i!=vecnum-1){
                        newa.print(d, aspeed, e, o, S[1], S[2], S[3], S[4]);
                        cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                    }
             }
            BM[bm]=2, BE[be]=e, BO[bo]=o, BS[bs]=aspeed;
            bm++,be++,bo++,bs++;
        }
        else if(p=='O'){
             int j,ch2control=0;
             int oxygenLen= O[0]/10;
             int ospeed = 20;
             Submarine news;

             if(i==0) {
                 news.print(d, 0, e, o, O[1], O[2], O[3]);
                 cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                 cout << "Next Move? (1,2)\n"<<"CP-2018-14385> ";
                 cin >> ch;
             }

                ospeed -= news.calspeed(O[3]);
                for(j=0; j<oxygenLen; j++){
                    e-=news.econsume(O[1],O[2]);
                    d+=10;
                    o-=O[2]/50*5;
                    if(o<=0) o=0;
                    if(e<=0) e=0;

                    graphic++;
                    if(i<vecnum-1 || j<oxygenLen-1){
                     if(e<=0) {
                        printFail(ch, j, graphic, d, 0, o, 10,temp);
                        BM[bm]=3, BE[be]=0, BO[bo]=o, BS[bs]=ospeed;
                        bm++,be++,bo++,bs++;
                        blackbox(bm,be,bo,bs);
                        cout<<"\n-----------------------"<<endl;
                        endcondi=0;
                        break;
                     }
                     if(o<=0) {
                        printFail(ch, j, graphic, d, e, 0, 10,temp);
                        BM[bm]=3, BE[be]=e, BO[bo]=0, BS[bs]=ospeed;
                        bm++,be++,bo++,bs++;
                        blackbox(bm,be,bo,bs);
                        cout<<"\n-----------------------"<<endl;
                        endcondi=0;
                        break;
                     }
                    }

                    if(ch==1 && (i<vecnum-1 || j<oxygenLen-1)){
                        printf("Successfully moved to next 10 km\n");
                        news.print(d,ospeed, e, o, O[1], O[2], O[3]);
                        cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                        if(j< oxygenLen-1){
                            cout << "Next Move? (1,2)\n"<<"CP-2018-14385> ";
                            cin >> ch;
                            ch2control++;
                        }
                    }
                }
                if(endcondi==0) break;
                if(ch==2 && ch2control!=j) {
                    printf("Successfully moved to next %d km\n", O[0]-ch2control*10);
                    if(i!=vecnum-1){
                        news.print(d, ospeed, e, o, O[1], O[2], O[3]);
                        cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
                    }
                }
            BM[bm]=3, BE[be]=e, BO[bo]=o, BS[bs]=ospeed;
            bm++,be++,bo++,bs++;
        }

        if(i!=vecnum-1){
            if(getinput(gettext(testnum)[i+1])=='X'){
                if(select==1){
                    srand((unsigned int)time(NULL));
                    int xr=rand()%100;
                    if(xr<20) {
                        printFail(ch,0,graphic,d,e,o,0,temp);
                        blackbox(bm,be,bo,bs);
                        endcondi=0;
                        cout<<"\n-----------------"<<endl;
                        break;
                    }
                    else e-=100;

                    if(e<=0) {
                        e=0;
                        printFail(1, 0, graphic, d, e, o, 0,temp);
                        blackbox(bm,be,bo,bs);
                        cout<<"\n-----------------------"<<endl;
                        endcondi=0;
                        break;
                     }
                }
                    i++;
            }
            if(getinput(gettext(testnum)[i+1])=='Y'){
                if(select ==1) {
                    srand((unsigned int)time(NULL));
                    int yr=rand()%100;
                    if(yr<35) {
                        printFail(ch,0,graphic,d,e,o,0,temp);
                        blackbox(bm,be,bo,bs);
                        cout<<"\n-----------------"<<endl;
                        endcondi=0;
                        break;
                    }
                    else{
                        srand((unsigned int)time(NULL));
                        int newyr=rand()%100;
                        if(newyr<50){
                            if(p=='R') solar=1;
                            else if(p=='S' || p=='O') o-=30;
                            if(o<=0) {
                                o=0;
                                printFail(1, 0, graphic, d, e, o, 0,temp);
                                blackbox(bm,be,bo,bs);
                                cout<<"\n-----------------------"<<endl;
                                endcondi=0;
                                break;
                            }
                         }
                    }
                 }
                i++;
            }
            cout << "Next Move? (1,2)" << endl;
            cout << "CP-2018-14385> ";
            cin >> ch;
        }
    }
    if(endcondi!=0){
        printf(" Final Status :\n Distance : %d km\n Energy : %d\n Oxygen Level : %d\n\n", d,e,o);
        cout<<temp.substr(0,graphic+1)+"@"+temp.substr(graphic+1,temp.length()-graphic-1)<<endl;
        cout<<"\n!FINISHED : Arrived" << endl;
        blackbox(bm,be,bo,bs);
        cout<<"\n-----------------------"<<endl;
    }
  }
    return 0;
}
