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
    //閒家前兩張牌
    while(true){
        player.clear();
        dealer.clear();
        cout<<"\n閒家: ";

        int a,sum_player,sum_dealer;  sum_player=0;sum_dealer=0;a=0;
        for(int i=0;i<2;i++){
            cin>>a;
            player.push_back(a);
        }

        //莊家前兩張牌
        cout<<"莊家: ";
        for(int i=0;i<2;i++){
            cin>>a;
            dealer.push_back(a);
        }

        //算點數
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
        //判斷補牌   代勘誤
        while(true){
            if(sum_player>=8 || sum_dealer>=8) break;
            else if(sum_player<=5){
                cout<<"閒家補牌: ";
                cin>>a;
                player.push_back(a);
                if(sum_dealer<=2){
                    cout<<"莊家補牌: ";
                    cin>>a;
                    dealer.push_back(a);
                }
                else if(sum_dealer==3 && a!=8){
                    cout<<"莊家補牌: ";
                    cin>>a;
                    dealer.push_back(a);
                }
                else if(sum_dealer==4 && a!=1 && a!=0 && a<8){
                    cout<<"莊家補牌: ";
                    cin>>a;
                    dealer.push_back(a);
                }
                else if(sum_dealer==5 && a!=0 && a!=1 && a!=2 && a!=3 && a!=8 && a!=9){
                    cout<<"莊家補牌: ";
                    cin>>a;
                    dealer.push_back(a);
                }
                else if(sum_dealer==6 && a>=6 && a<=7){
                    cout<<"莊家補牌: ";
                    cin>>a;
                    dealer.push_back(a);
                }
            }
            else if(sum_dealer<=5){
                cout<<"莊家補牌: ";
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


        // cout<<"閒家牌: ";
        // for(int i:player) cout<<i<<" ";
        // cout<<"\n閒家差距: "<<dif(player[0],player[player.size()-1])<<"\n";
        // cout<<"最大點數: "<<highest_point(player[player.size()-1])<<"\n";
        // cout<<"點數: "<<point_player<<" "<<point[point_player]<<"\n";
        // cout<<"閒家: "<<final_player<<endl;
        // cout<<"莊家: "<<final_dealer<<endl;
        // cout<<"莊家差距: "<<dif(dealer[0],dealer[dealer.size()])<<"\n";
        cout<<fixed<<setprecision(2)<<"閒家: "<<final_player<<endl;
        cout<<fixed<<setprecision(2)<<"莊家: "<<final_dealer<<endl;
        if(final_player>final_dealer) cout<<"優: <閒家>" <<final_player/final_dealer<<"倍\n";
        else if(final_player==final_dealer) cout<<"平\n";
        else cout<<"優: <莊家> "<<final_dealer/final_player<<"倍\n";
     }
}
