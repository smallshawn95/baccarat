#include <bits/stdc++.h>
using namespace std;


// vector<int> player;
vector<int> dealer;
int dif(int x,int y){
    return y-x;
}

// int point_player(){
//     int sum=0;
//     for(int i=0;i<player.size();i++){
//         sum+=player[i];
//         if (sum>=10){
//             sum-=10;
//         }
//         return sum;
//     }
// }

// int point_dealer(){
//     int sum=0;
//     for(int i=0;i<dealer.size();i++){
//         sum+=dealer[i];
//         if (sum>=10){
//             sum-=10;
//         }
//     }
//     return sum;
// }

int highest_point(int x){
    if(x<=6){
        return 1;
    }
    else return x-5;
}
float point[10]={0.5,0.9,0.7,0.7,0.8,0.5,0.4,0.3,0.2,0.3};

int main(){
    //���a�e��i�P
    while(true){
        player.clear();
        dealer.clear();
        cout<<"\n���a: ";

        int a,sum_player,sum_dealer;  sum_player=0;sum_dealer=0;a=0;
        for(int i=0;i<2;i++){
            cin>>a;
            player.push_back(a);
        }

        //���a�e��i�P
        cout<<"���a: ";
        for(int i=0;i<2;i++){
            cin>>a;
            dealer.push_back(a);
        }

        //���I��
        for(int i=0;i<2;i++){
            if(player[i]>=10){
                sum_player+=0;
            }
            else{
                sum_player+=player[i];
            }
            if(dealer[i]>=10){
                sum_dealer+=0;
            }
            else{
                sum_dealer+=dealer[i];
            }
            if(sum_player>=10) sum_player-=10;
            if(sum_dealer>=10) sum_dealer-=10;
        }


// ---------------------------------------------------------------------------------------
        //�P�_�ɵP   �N�ɻ~
        while(true){
            if(sum_player>=8 || sum_dealer>=8) break;
            else if(sum_player<=5){
                cout<<"���a�ɵP: ";
                cin>>a;
                player.push_back(a);
                if(sum_dealer<=2){
                    cout<<"���a�ɵP: ";
                    cin>>a;
                    dealer.push_back(a);
                }
                else if(sum_dealer==3 && a!=8){
                    cout<<"���a�ɵP: ";
                    cin>>a;
                    dealer.push_back(a);
                }
                else if(sum_dealer==4 && a!=1 && a!=0 && a<8){
                    cout<<"���a�ɵP: ";
                    cin>>a;
                    dealer.push_back(a);
                }
                else if(sum_dealer==5 && a!=0 && a!=1 && a!=2 && a!=3 && a!=8 && a!=9){
                    cout<<"���a�ɵP: ";
                    cin>>a;
                    dealer.push_back(a);
                }
                else if(sum_dealer==6 && a>=6 && a<=7){
                    cout<<"���a�ɵP: ";
                    cin>>a;
                    dealer.push_back(a);
                }
            }
            else if(sum_dealer<=5){
                cout<<"���a�ɵP: ";
                cin>>a;
                dealer.push_back(a);
            }
            break;
        }
// -----------------------------------------------------------------------------------------------------------
        sort(player.begin(),player.end());
        sort(dealer.begin(),dealer.end());

        int point_player=0;
        for(int i=0;i<player.size();i++){
            if(player[i]>=10) point_player+=0;
            else point_player+=player[i];
            if(point_player>=10) point_player-=10;
        }

        int point_dealer=0;
        for(int i=0;i<dealer.size();i++){
           if(dealer[i]>=10) point_dealer+=0;
           else point_dealer+=dealer[i];
           if(point_dealer>=10) point_dealer-=10;
        }


        long double final_player,final_dealer; final_player=0;final_dealer=0;
        final_player=(dif(player[0],player[player.size()-1])+highest_point(player[player.size()-1]))*1.0/(point[point_player]);
        final_dealer=(dif(dealer[0],dealer[dealer.size()-1])+highest_point(dealer[dealer.size()-1]))*1.0/(point[point_dealer]);


        // cout<<"���a�P: ";
        // for(int i:player) cout<<i<<" ";
        // cout<<"\n���a�t�Z: "<<dif(player[0],player[player.size()-1])<<"\n";
        // cout<<"�̤j�I��: "<<highest_point(player[player.size()-1])<<"\n";
        // cout<<"�I��: "<<point_player<<" "<<point[point_player]<<"\n";
        // cout<<"���a: "<<final_player<<endl;
        // cout<<"���a: "<<final_dealer<<endl;
        // cout<<"���a�t�Z: "<<dif(dealer[0],dealer[dealer.size()])<<"\n";
        cout<<fixed<<setprecision(2)<<"���a: "<<final_player<<endl;
        cout<<fixed<<setprecision(2)<<"���a: "<<final_dealer<<endl;
        if(final_player>final_dealer) cout<<"�u: <���a>" <<final_player/final_dealer<<"��\n";
        else if(final_player==final_dealer) cout<<"��\n";
        else cout<<"�u: <���a> "<<final_dealer/final_player<<"��\n";
     }
}
