//
// Arduino STM32 NTSCビデオ出力 サンプル V2.2
// 最終更新日 2017/02/17 たま吉さん
// Blue Pillボード(STM32F103C8)にて動作確認
//
//  修正履歴
//    2017/02/17 水平・垂直同期信号をPWM出力で行うように変更,解像度を224x216に変更
//    2017/02/20 NTSCビデオ表示部をライブラリ化
//    2017/03/03 解像度モード追加
//    2017/06/25 オブジェクトを動的に生成する仕様変更対応
//    2017/11/18 NTSCオブジェクトのグローバル化対応
//

#include "TNTSC.h"
#include <Adafruit_GFX.h>


TNTSC_class TNTSC(4,1);

void setup(){
  pinMode(PC13,OUTPUT);
}

void loop(){
    TNTSC.begin(); // 第2引数でSPI 1,2を指定(デフォルト 1))
    TNTSC.adjust(0);  // Vertical sync signal correction (default 0)
    //TNTSC.cls();
    TNTSC.drawRect(0, 0, 100, 100, 1);
    delay(2500);  
    digitalWrite(PC13,HIGH); 
    delay(2500);  
    digitalWrite(PC13,LOW); 
    TNTSC.end();
}
