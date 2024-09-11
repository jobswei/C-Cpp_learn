#include<iostream>

using namespace std;
// 閲嶈浇鍑芥暟銆傚弬鏁板繀椤讳笉鍚屻€備笉鑳介€氳繃杩斿洖鍊间笉鍚屾潵閲嶈浇鍑芥暟
class printData{
    public:
        void print(int input){
            cout<<"Int is: "<<input<<endl;
        }
        void prin(double input){
            cout<<"Double is: "<<input<<endl;
        }
};
// 杩愮畻绗﹂噸杞�
/*
鍦ㄤ綘鎻愪緵鐨勪唬鐮佷腑锛屾嫹璐濇瀯閫犲嚱鏁� Box(const Box& obj) 鍙互璁块棶鍙傛暟 obj 鐨勭鏈夋垚鍛� length銆�
杩欐槸鍥犱负鎷疯礉鏋勯€犲嚱鏁版槸绫荤殑鎴愬憳鍑芥暟锛屽洜姝ゅ畠鍙互璁块棶鍚岀被鐨勫叾浠栧璞＄殑绉佹湁鎴愬憳銆�
*/
class Box{
    int length;

    public:
        Box(int length):length(length){};
        int getLength() const{
            return length;
        }

        Box operator+(const Box& b){
            Box box(this->length+b.length);// 鍙互鐩存帴璁块棶private鐨勫師鍥犲啓鍦ㄤ笂闈�
            return box;
        }
};
// 涔熷彲浠ュ皢杩愮畻绗﹂噸杞藉畾涔夊湪澶栭潰
Box operator-(const Box& a,const Box& b){
    Box box(a.getLength()-b.getLength());// 杩欎釜鍑芥暟涓嶆槸绫荤殑鍐呯疆鍑芥暟锛屾棤娉曠洿鎺ヨ闂甽ength
                                        // 鎵€浠ュ彧鑳戒娇鐢╣etLength锛岃€屼笖瑕佸湪getLength鐨勫畾涔変腑鍔犱笂const
    return box;
};

int main(){
    Box box1(10),box2(5);
    Box box3=box1+box2;
    cout<<box3.getLength()<<endl;
    box3=box1-box2;
    cout<<box3.getLength()<<endl;

    return 0;
}