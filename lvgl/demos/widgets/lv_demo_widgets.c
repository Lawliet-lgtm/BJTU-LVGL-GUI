/*********************
 *      INCLUDES
 *********************/
#include "lv_demo_widgets.h"
#include<time.h>
#include<stdio.h>

#if LV_USE_DEMO_WIDGETS

#if LV_MEM_CUSTOM == 0 && LV_MEM_SIZE < (38ul * 1024ul)
    #error Insufficient memory for lv_demo_widgets. Please set LV_MEM_SIZE to at least 38KB (38ul * 1024ul).  48KB is recommended.
#endif
/**********************
 *  STATIC VARIABLES
 **********************/
 static lv_obj_t * screen=NULL;
 static lv_obj_t * videoScreen=NULL;
 static lv_obj_t * watchScreen=NULL;
 static lv_obj_t * shopScreen=NULL;
 static lv_obj_t * bandAidBuyScreen=NULL;
 static lv_obj_t * brushBuyScreen=NULL;
 static lv_obj_t * maskBuyScreen=NULL;
 static lv_obj_t * noteBookBuyScreen=NULL;
 static lv_obj_t * recyclebagBuyScreen=NULL;
 static lv_obj_t * rubbishBagBuyScreen=NULL;
 static lv_obj_t * strawBuyScreen=NULL;
 static lv_obj_t * tablewareBuyScreen=NULL;
 static lv_obj_t * wetwipeBuyScreen=NULL;
 static lv_obj_t * helpScreen=NULL;
 static lv_obj_t * paySuccessScreen=NULL;

 static const lv_font_t * goShopFont=NULL;


 static lv_style_t screenBackgroundStyle;
 static lv_style_t goShopBtnStyle;
 static lv_style_t goShopBtnPressedStyle;
 static lv_style_t goShopLabelStyle;
 static lv_style_t welcomeLabelStyle;
 static lv_style_t watchScreenStyle;
 static lv_style_t shopScreenStyle;
 static lv_style_t bandAidBuyScreenStyle;
 static lv_style_t brushBuyScreenStyle;
 static lv_style_t maskBuyScreenStyle;
 static lv_style_t noteBookBuyScreenStyle;
 static lv_style_t recyclebagBuyScreenStyle;
 static lv_style_t rubbishBagBuyScreenStyle;
 static lv_style_t strawBuyScreenStyle;
 static lv_style_t tablewareBuyScreenStyle;
 static lv_style_t wetwipeBuyScreenStyle;
 static lv_style_t helpScreenStyle;
 static lv_obj_t paySuccessScreenStyle;

 static lv_obj_t * lvMinute=NULL;
 static lv_obj_t * lvHour=NULL;
 static lv_obj_t * lvSecond=NULL;

 static uint8_t Minute =59;
 static uint8_t Hour =8;
 static uint8_t Second=2 ;

 const char * data = "https://www.baidu.com";

 LV_IMG_DECLARE(watch_bg);
 LV_IMG_DECLARE(hour);
 LV_IMG_DECLARE(minute);
 LV_IMG_DECLARE(second);

 LV_IMG_DECLARE(bandAid);
 LV_IMG_DECLARE(brush);
 LV_IMG_DECLARE(mask);
 LV_IMG_DECLARE(notebook);
 LV_IMG_DECLARE(recycle_bag);
 LV_IMG_DECLARE(rubbishBag);
 LV_IMG_DECLARE(straw);
 LV_IMG_DECLARE(tableware);
 LV_IMG_DECLARE(wet_wipe);

 LV_IMG_DECLARE(bigBandAid);
 LV_IMG_DECLARE(bigBrush);
 LV_IMG_DECLARE(big_mask);
 LV_IMG_DECLARE(bigNotebook);
 LV_IMG_DECLARE(big_recycle_bag);
 LV_IMG_DECLARE(bigrubbishBag);
 LV_IMG_DECLARE(bigStraw);
 LV_IMG_DECLARE(bigTableware);
 LV_IMG_DECLARE(big_wet_wipe);

 LV_IMG_DECLARE(help);

 LV_IMG_DECLARE(paySuccess);
 
 LV_IMG_DECLARE(helpSign);

 typedef struct _lv_clock
{
    lv_obj_t *time_label; // 时间标签
    lv_obj_t *date_label; // 日期标签
    lv_obj_t *weekday_label; // 星期标签
}lv_clock_t;

 static lv_style_t date_time_clock_style; // 最外层对象的样式
 static lv_style_t time_style; // 时间对象样式
 static lv_style_t date_style; // 日期对象样式
 static lv_style_t time_label_style; // 时间标签样式
 static lv_style_t date_label_style; // 日期标签样式
 static lv_style_t week_lable_style; // 日期标签样式

 static lv_style_t nameStyle; //商品名称样式
 static lv_style_t priceStyle;  //商品价格样式
 static lv_style_t buyLabelStyle; //buy标签样式

 static lv_style_t bigNameStyle; //支付界面商品名称样式
 static lv_style_t bigPriceStyle; //支付界面商品价格样式

 static lv_style_t helpContentStyle; //help界面文字样式

 static lv_style_t countdownStyle;  //倒计时文字样式

 static lv_style_t paySuccessLabelStyle; //支付成功文字样式

 static lv_style_t backToFirstBtnStyle; //返回按键样式
 static lv_style_t backToFirstBtnLabelStyle; //返回按键标签字体样式

 static lv_style_t MacStyle;
 static lv_style_t helpBtnStyle;

 static lv_style_t timeLookBtnStyle;
 static lv_style_t timeLookBtnPressedStyle;



 static const lv_font_t * nameFont=NULL;
 static const lv_font_t * priceFont=NULL;
 static const lv_font_t * buyLabelFont=NULL;

 static const lv_font_t * bigNameFont = NULL;
 static const lv_font_t * bigPriceFont = NULL;

 static const lv_font_t * helpContentFont = NULL;

 static const lv_font_t * countdownStyleFont = NULL;

 static lv_obj_t * countdownLabel = NULL;

 static const lv_font_t * paySuccessLabelStyleFont = NULL;

 static const lv_font_t * backToFirstBtnLabelStyleFont = NULL;

 static const lv_font_t * MacStyleFont = NULL;

 static uint8_t hidCountdown1 = 8;
 static uint8_t hidCountdown2 = 8;
 static uint8_t hidCountdown3 = 8;
 static uint8_t hidCountdown4 = 8;
 static uint8_t hidCountdown5 = 8;
 static uint8_t hidCountdown6 = 8;
 static uint8_t hidCountdown7 = 8;
 static uint8_t hidCountdown8 = 8;
 static uint8_t hidCountdown9 = 8;

 static uint8_t countdown1=60;  //支付成功界面返回page1倒计时
 static lv_timer_t * countdownTime1 = NULL;



/**********************
 *   STATIC FUNCTIONS
 **********************/

/**********************
 *   PAGE1:video
 **********************/
 static lv_img_dsc_t IMG1 = {
    .header.cf = LV_IMG_CF_RAW,
    .header.always_zero = 0,
    .header.reserved = 0,
    .header.w = 0,
    .header.h = 0,
    .data_size = 0,
    .data = NULL,
};
static const	unsigned char JFIF_INFO[18]=
{0XFF ,0XE0 ,0X00 ,0X10 ,0X4A ,0X46 ,0X49 ,0X46 ,0X00 ,0X01 ,0X01 ,0X01 ,0X00 ,0X60 ,0X00 ,0X60 ,0X00 ,0X00};
static lv_obj_t * g_scr=NULL;
static int avi_file_is_opened=0;
static char frameBuffer[20*1024];
static int frameSize = 0;      //单帧的字节数
static int keyFrame = 0;       //是否关键帧
static int pos;                //帧索引
static int frames;             //帧总数
static avi_t * avi=NULL;


static void goShopBtnCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(videoScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }

}

static void lookTimeBtnCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(videoScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(watchScreen,LV_OBJ_FLAG_HIDDEN);
    }

}

static void watchBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(watchScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(videoScreen,LV_OBJ_FLAG_HIDDEN);
    }

}

static void helpBtnCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(helpScreen,LV_OBJ_FLAG_HIDDEN);
    }

}

static void helpBackBtnCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(helpScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }

}

static void paySuccessBackBtnCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        countdown1=60;



        lv_timer_del(countdownTime1);


        lv_obj_add_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(videoScreen,LV_OBJ_FLAG_HIDDEN);

        lv_label_set_text_fmt(countdownLabel,"%u",countdown1);
        lv_obj_align(countdownLabel,LV_ALIGN_BOTTOM_MID,0,0);

    }

}

static void bandAidBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(bandAidBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}
static void brushBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(brushBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void maskBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(maskBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void notebookBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(noteBookBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void recyclebagBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(recyclebagBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void rubbishBagBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(rubbishBagBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void strawBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(strawBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void tablewareBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(tablewareBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void wetwipeBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(wetwipeBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void shopBackCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(videoScreen,LV_OBJ_FLAG_HIDDEN);
    }
}

static void updateCountdown1(lv_timer_t * tmr)
{
    if(countdown1>0)
    {
        countdown1--;
        lv_label_set_text_fmt(countdownLabel,"%u",countdown1);
        lv_obj_align(countdownLabel,LV_ALIGN_BOTTOM_MID,0,0);
    }

    if(countdown1==0)
    {
        countdown1=60;

        lv_obj_add_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(videoScreen,LV_OBJ_FLAG_HIDDEN);

        lv_label_set_text_fmt(countdownLabel,"%u",countdown1);
        lv_obj_align(countdownLabel,LV_ALIGN_BOTTOM_MID,0,0);


        lv_timer_del(countdownTime1);


    }
}

static void bandAidHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown1>0);
    else
    {
        lv_obj_add_flag(bandAidBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown1=8;
    }
}
static void brushHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown2>0);
    else
    {
        lv_obj_add_flag(brushBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown2=8;
    }
}

static void maskHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown3>0);
    else
    {
        lv_obj_add_flag(maskBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown3=8;
    }
}

static void notebookHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown4>0);
    else
    {
        lv_obj_add_flag(noteBookBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown4=8;
    }
}

static void recyclebagHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown5>0);
    else
    {
        lv_obj_add_flag(recyclebagBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown5=8;
    }
}

static void rubbishBagHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown6>0);
    else
    {
        lv_obj_add_flag(rubbishBagBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown6=8;
    }
}
static void strawHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown7>0);
    else
    {
        lv_obj_add_flag(strawBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown7=8;
    }
}

static void tablewareHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown8>0);
    else
    {
        lv_obj_add_flag(tablewareBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown8=8;
    }
}

static void wetwipeHidBackCB(lv_timer_t * tmr)
{
    if(--hidCountdown9>0);
    else
    {
        lv_obj_add_flag(wetwipeBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
        countdownTime1 = lv_timer_create(updateCountdown1,1000,NULL);
        hidCountdown9=8;
    }
}

static void bandAidBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(bandAidBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(bandAidHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);
    }

}

static void brushBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(brushBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(brushHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);
    }

}
static void maskBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(maskBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(maskHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);
    }

}

static void notebookBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(noteBookBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(notebookHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);
    }

}

static void recyclebagBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(recyclebagBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(recyclebagHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);
    }

}

static void rubbishBagBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(rubbishBagBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(rubbishBagHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);
    }

}

static void strawBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(strawBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(strawHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);
    }

}

static void tablewareBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(tablewareBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(tablewareHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);
    }

}

static void wetwipeBuyCB(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(wetwipeBuyScreen,LV_OBJ_FLAG_HIDDEN);
        lv_timer_t * countdownTime = lv_timer_create(wetwipeHidBackCB,1000,NULL);
        lv_timer_set_repeat_count(countdownTime, 8);

    }

}
static void pic_timer(lv_timer_t * tmr)
{
    //lv_obj_t* bg = timer->user_data;
    if(avi_file_is_opened){
        pos++;
        if(pos<frames){
            //  avi->pos  会自动增加，不用下面的函数
            //AVI_set_video_position((avi_t *) avi,pos);
            frameSize = AVI_read_frame((avi_t *) avi, frameBuffer, &keyFrame);
            //  图片的尺寸不能大于分配的空间
            if(frameSize > sizeof(frameBuffer))     return;
            printf("pos:%d,frameSize: %d,frames=%d\n",pos, frameSize,frames);

            IMG1.data_size = frameSize;
            memcpy(frameBuffer+2,JFIF_INFO,sizeof(JFIF_INFO));
            IMG1.data = (const uint8_t *)frameBuffer;

            lv_img_set_src(g_scr,&IMG1);

        }else{
//            printf("frames=%d,avi file close.",frames);
//            avi_file_is_opened = 0;
//            AVI_close((avi_t *) avi);
            pos=50;
            AVI_set_video_position((avi_t *) avi,pos);
            frameSize = AVI_read_frame((avi_t *) avi, frameBuffer, &keyFrame);
            //  图片的尺寸不能大于分配的空间
            if(frameSize > sizeof(frameBuffer))     return;
            printf("pos:%d,frameSize: %d,frames=%d\n",pos, frameSize,frames);

            IMG1.data_size = frameSize;
            memcpy(frameBuffer+2,JFIF_INFO,sizeof(JFIF_INFO));
            IMG1.data = (const uint8_t *)frameBuffer;

            lv_img_set_src(g_scr,&IMG1);



        }
    }

}
static void pageOne(void)
{
    /**********************
     *   page1屏幕背景样式
     **********************/
    lv_style_init(&screenBackgroundStyle);          //初始化style
    lv_style_set_radius(&screenBackgroundStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&screenBackgroundStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&screenBackgroundStyle,lv_palette_main(LV_PALETTE_BLUE)); //蓝色背景色

    /**********************
     *   page1按钮样式
     **********************/
    lv_style_init(&goShopBtnStyle);
    lv_style_set_radius(&goShopBtnStyle,5);
    lv_style_set_bg_opa(&goShopBtnStyle,LV_OPA_COVER);
    lv_style_set_bg_color(&goShopBtnStyle,lv_palette_main(LV_PALETTE_GREEN)); //绿色背景色


    lv_style_init(&timeLookBtnStyle);
    lv_style_set_radius(&timeLookBtnStyle,5);
    lv_style_set_bg_opa(&timeLookBtnStyle,LV_OPA_COVER);
    lv_style_set_bg_color(&timeLookBtnStyle,lv_palette_main(LV_PALETTE_PINK)); //绿色背景色
   

    lv_style_init(&welcomeLabelStyle);
    lv_style_set_radius(&welcomeLabelStyle,5);
    lv_style_set_bg_opa(&welcomeLabelStyle,LV_OPA_COVER);
    lv_style_set_bg_color(&welcomeLabelStyle,lv_palette_main(LV_PALETTE_CYAN)); //绿色背景色



    videoScreen=lv_obj_create(screen);
    lv_obj_align(videoScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(videoScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(videoScreen,&screenBackgroundStyle,0);

    char *ff="../../avi/env8.avi";
    avi = AVI_open_input_file(ff, 1);
    if(avi != NULL){
        avi_file_is_opened = 1;
        printf("W: %d,H: %d\n", (int)(avi->width),(int)(avi->height));
        //将avi帧byte读取到bitmap中
        pos = 50;
        frames=AVI_video_frames(avi);

        AVI_set_video_position((avi_t *) avi,pos);
            frameSize = AVI_read_frame((avi_t *) avi, frameBuffer, &keyFrame);
        printf("pos:%d,frameSize: %d,frames=%d\n",pos, frameSize,frames);


    }else{
        printf("open avi fail.");
        exit(0);
    }

        IMG1.data_size = frameSize;
        IMG1.data = (const uint8_t *)frameBuffer;


        g_scr =  lv_img_create(videoScreen);
        lv_img_set_src(g_scr,&IMG1);


    lv_timer_t * timer = lv_timer_create(pic_timer, 20,  g_scr);

    lv_obj_t * goShopBtn=lv_btn_create(videoScreen);
    lv_obj_remove_style_all(goShopBtn);
    lv_obj_add_style(goShopBtn,&goShopBtnStyle,0);
    lv_obj_add_style(goShopBtn,&goShopBtnPressedStyle,LV_STATE_PRESSED);
    lv_obj_set_size(goShopBtn,300,200);
    lv_obj_align(goShopBtn,LV_ALIGN_TOP_RIGHT,-200,20);
    lv_obj_add_event_cb(goShopBtn,goShopBtnCB,LV_EVENT_ALL,NULL);


    goShopFont=&lv_font_montserrat_40;
    lv_style_set_text_font(&goShopLabelStyle,goShopFont);
    lv_style_set_text_font(&welcomeLabelStyle,goShopFont);

    lv_obj_t* goShopLabel=lv_label_create(goShopBtn);
    lv_obj_remove_style_all(goShopLabel);
    lv_obj_add_style(goShopLabel,&goShopLabelStyle,0);
    lv_label_set_text(goShopLabel,"Go\nShopping!");
    lv_obj_center(goShopLabel);

    lv_obj_t * timeLookBtn=lv_btn_create(videoScreen);
    lv_obj_remove_style_all(timeLookBtn);
    lv_obj_add_style(timeLookBtn,&timeLookBtnStyle,0);
    lv_obj_add_style(timeLookBtn,&timeLookBtnPressedStyle,LV_STATE_PRESSED);
    lv_obj_set_size(timeLookBtn,200,200);
    lv_obj_align(timeLookBtn,LV_ALIGN_TOP_RIGHT,-250,270);
    lv_obj_add_event_cb(timeLookBtn,lookTimeBtnCB,LV_EVENT_ALL,NULL);

    lv_obj_t* timeLookLabel=lv_label_create(timeLookBtn);
    lv_obj_remove_style_all(timeLookLabel);
    lv_obj_add_style(timeLookLabel,&goShopLabelStyle,0);
    lv_label_set_text(timeLookLabel,"Look\nTime!");
    lv_obj_center(timeLookLabel);

    lv_obj_t * welcomeLabel=lv_label_create(videoScreen);
    lv_obj_remove_style_all(welcomeLabel);
    lv_obj_add_style(welcomeLabel,&welcomeLabelStyle,0);
    lv_label_set_text(welcomeLabel,"             Hello~~\n\n             Welcome to BJTU!             \n");
    lv_obj_align(welcomeLabel,LV_ALIGN_BOTTOM_MID,0,-50);

}

static void update_time(lv_timer_t * tmr)
{
    time_t now_t;
    char strftime_buf[64];


    if(lvHour !=NULL)
    {

       // Hour,Minute,Second;

        uint16_t h = Hour * 300 + Minute / 12 % 12 * 60;
        lv_img_set_angle(lvHour, h);
        lv_img_set_angle(lvMinute, Minute * 6 * 10);

        lv_img_set_angle(lvSecond, Second * 6 * 10);
        printf("h %d m %d s %d\n", Hour, Minute, Second);

    }

    if (++Second >= 60)
    {
        Second = 0;
        if (++Minute >= 60)
        {
            Minute = 0;
            if (++Hour >= 12) Hour = 0;
        }

    }
}

static void clock_date_task_callback(lv_timer_t *timer)
{
    static const char *week_day[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    static time_t unix_time;
    static struct tm *time_info;

    unix_time = time(NULL);
    time_info = localtime(&unix_time);

    int year = time_info->tm_year+1900;
    int month = time_info->tm_mon + 1;
    int day = time_info->tm_mday;
    int weekday = time_info->tm_wday;
    int hour = time_info->tm_hour;
    int minutes = time_info->tm_min;
    int second = time_info->tm_sec;

    if (timer != NULL && timer->user_data != NULL)
    {
        lv_clock_t * clock = (lv_clock_t *)(timer->user_data);
        if (clock->time_label != NULL)
        {
            lv_label_set_text_fmt(clock->time_label, "%02d:%02d:%02d", hour, minutes, second);
            lv_obj_align_to(clock->time_label, lv_obj_get_parent(clock->time_label), LV_ALIGN_CENTER, 0, 0);
        }

        if (clock->date_label != NULL)
        {
            lv_label_set_text_fmt(clock->date_label, "%d-%02d-%02d", year, month, day);
            lv_obj_align_to(clock->date_label, lv_obj_get_parent(clock->date_label), LV_ALIGN_TOP_MID, 2, 0);
        }

         if (clock->weekday_label != NULL)
         {
            lv_label_set_text_fmt(clock->weekday_label, "%s", week_day[weekday]);
            lv_obj_align_to(clock->weekday_label, lv_obj_get_parent(clock->weekday_label), LV_ALIGN_BOTTOM_MID, -2, 0);
         }
    }
}

static void pageTwo(void)
{
    /**********************
     *   page2屏幕背景样式
     **********************/
    lv_style_init(&watchScreenStyle);          //初始化style
    lv_style_set_radius(&watchScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&watchScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&watchScreenStyle,lv_palette_main(LV_PALETTE_BLUE)); //蓝色背景色

    watchScreen=lv_obj_create(screen);
    lv_obj_align(watchScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(watchScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(watchScreen,&watchScreenStyle,0);

    /**********************
     *   page2显示时间样式
     **********************/

    lv_style_reset(&date_time_clock_style); // 重置样式
    lv_style_init(&date_time_clock_style); // 初始化样式
    lv_style_set_radius(&date_time_clock_style, 5); // 设置样式圆角
    lv_style_set_bg_opa(&date_time_clock_style, LV_OPA_20); // 设置样式背景透明度
    lv_style_set_border_width(&date_time_clock_style, 0); // 设置样式边框宽度
    lv_style_set_bg_color(&date_time_clock_style, lv_color_white()); // 设置样式背景颜色，白色
    lv_style_set_pad_left(&date_time_clock_style, 1); // 设置样式左边padding填充宽度
    lv_style_set_pad_right(&date_time_clock_style, 1); // 设置样式右边padding填充宽度
    lv_style_set_pad_top(&date_time_clock_style, 0); // 设置样式顶部padding填充宽度
    lv_style_set_pad_bottom(&date_time_clock_style, 0); // 设置样式底部padding填充宽度


    lv_style_reset(&time_style);
    lv_style_init(&time_style);
    lv_style_set_bg_opa(&time_style, LV_OPA_COVER);
    lv_style_set_border_width(&time_style, 0);
    lv_style_set_radius(&time_style, 5);
    lv_style_set_bg_color(&time_style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_pad_left(&time_style, 0);
    lv_style_set_pad_right(&time_style, 0);
    lv_style_set_pad_top(&time_style, 0);
    lv_style_set_pad_bottom(&time_style, 0);


    lv_style_reset(&date_style);
    lv_style_init(&date_style);
    lv_style_set_bg_opa(&date_style, LV_OPA_COVER);
    lv_style_set_border_width(&date_style, 0);
    lv_style_set_radius(&date_style, 5);
    lv_style_set_bg_color(&date_style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_pad_left(&date_style, 0);
    lv_style_set_pad_right(&date_style, 0);

	/* Time font */

    lv_style_reset(&time_label_style); // 重置样式
    lv_style_init(&time_label_style); // 初始化样式
    lv_style_set_text_color(&time_label_style , lv_color_white()); // 设置标签样式文本颜色
    lv_style_set_text_font(&time_label_style, &lv_font_montserrat_32); // 设置字体风格
    lv_style_set_text_opa(&time_label_style, LV_OPA_COVER); // 设置字体透明度
    lv_style_set_bg_opa(&time_label_style, LV_OPA_0); // 设置样式背景透明度

	/* Date font */

    lv_style_reset(&date_label_style);
    lv_style_init(&date_label_style);
    lv_style_set_text_opa(&date_label_style, LV_OPA_COVER);
    lv_style_set_bg_opa(&date_label_style, LV_OPA_0);
    lv_style_set_text_color(&date_label_style , lv_color_white());
    lv_style_set_text_font(&date_label_style, &lv_font_montserrat_16);

	/* Week font */

    lv_style_reset(&week_lable_style);
    lv_style_init(&week_lable_style);
    lv_style_set_text_opa(&week_lable_style, LV_OPA_COVER);
    lv_style_set_bg_opa(&week_lable_style, LV_OPA_0);
    lv_style_set_text_color(&week_lable_style, lv_color_white());
    lv_style_set_text_font(&week_lable_style, &lv_font_montserrat_16);

    lv_obj_t * img = lv_img_create(watchScreen);
    lv_img_set_src(img, &watch_bg);

    lv_obj_set_size(img, 200, 200);
   // lv_obj_set_auto_realign(img, true);
    lv_obj_align(img,  LV_ALIGN_CENTER, 0, 0);



    lvHour = lv_img_create(watchScreen);
    lv_img_set_src( lvHour, &hour);
    lv_obj_align(   lvHour,LV_ALIGN_CENTER, 0, 0);
    uint16_t h = Hour * 300 + Minute / 12 % 12 * 60;
    lv_img_set_angle(  lvHour, h);

    lvMinute = lv_img_create(watchScreen);
    lv_img_set_src( lvMinute, &minute);
    lv_obj_align(   lvMinute,LV_ALIGN_CENTER, 0, 0);
    lv_img_set_angle(  lvMinute, Minute*60);

    lvSecond = lv_img_create(watchScreen);


    lv_img_set_src( lvSecond, &second);
    lv_obj_align(   lvSecond,LV_ALIGN_CENTER, 0, 0);
    lv_img_set_angle(  lvSecond, Second*60);

     //lv_task_create_basic(update_time, 1000, LV_BASE_DIR_LTR, NULL);
    lv_timer_t * timer = lv_timer_create(update_time, 1000,  NULL);

    /* Time & Date */
    lv_obj_t *time_date_obj = lv_obj_create(watchScreen); // 基于屏幕创建时间日期对象
    if (time_date_obj == NULL)
    {
        printf("[%s:%d] time_date_obj create failed\n", __FUNCTION__, __LINE__);
        return;
    }

	lv_obj_set_size(time_date_obj, 320, 100); // 设置对象大小
    //lv_obj_center(time_date_obj); // 对象居屏幕中间显示
    lv_obj_align(time_date_obj,LV_ALIGN_TOP_LEFT,0,0);
	lv_obj_add_style(time_date_obj, &date_time_clock_style, LV_STATE_DEFAULT); //给time_date_obj对象添加样式

    /*Time display*/
    lv_obj_t *time_obj = lv_obj_create(time_date_obj); // 基于time_date_obj对象创建时间对象
    if (time_obj == NULL)
    {
        printf("[%s:%d] time_obj create failed\n", __FUNCTION__, __LINE__);
        return;
    }

    lv_obj_set_size(time_obj, 158, 100); // 设置对象大小
    lv_obj_align_to(time_obj, time_date_obj, LV_ALIGN_LEFT_MID, 0, 0); // 设置time_obj对象基于time_date_obj对象左边中间对齐
    lv_obj_add_style(time_obj, &time_style, LV_STATE_DEFAULT);  // 给time_obj对象添加样式

    static lv_clock_t lv_clock = { 0 };

    lv_clock.time_label = lv_label_create(time_obj); // 基于time_obj对象创建时间显示标签对象 lv_clock.time_label
    if (lv_clock.time_label == NULL)
    {
        printf("[%s:%d] time_label create failed\n", __FUNCTION__, __LINE__);
        return ;
    }

    lv_obj_add_style(lv_clock.time_label, &time_label_style, LV_STATE_DEFAULT); // 给对象 lv_clock.time_label添加样式

    /*Date display*/
    lv_obj_t *date_obj = lv_obj_create(time_date_obj); // 基于time_date_obj对象创建date_obj对象
    if (date_obj == NULL)
    {
        printf("[%s:%d] date_obj create failed\n", __FUNCTION__, __LINE__);
        return ;
    }
    lv_obj_set_size(date_obj, 158, 100); // 设置对象大小
    lv_obj_align_to(date_obj, time_date_obj, LV_ALIGN_RIGHT_MID, 0, 0); //设置date_obj对象基于time_date_obj对象右边中部对齐
    lv_obj_add_style(date_obj, &date_style, LV_STATE_DEFAULT); // 给date_obj对象添加样式

    lv_clock.date_label = lv_label_create(date_obj); // 基于date_obj对象创建lv_clock.date_label日期显示对象
    if (lv_clock.date_label == NULL)
    {
        printf("[%s:%d] date_label create failed\n", __FUNCTION__, __LINE__);
        return ;
    }
    lv_obj_add_style(lv_clock.date_label, &date_label_style, LV_STATE_DEFAULT); // 给lv_clock.date_label对象添加样式

    /*Week display*/
    lv_clock.weekday_label = lv_label_create(date_obj); // 基于date_obj对象创建星期显示lv_clock.weekday_label对象
    if (lv_clock.weekday_label == NULL)
    {
        printf("[%s:%d] weekday_label create failed\n", __FUNCTION__, __LINE__);
        return;
    }
    lv_obj_add_style(lv_clock.weekday_label, &week_lable_style, LV_STATE_DEFAULT); // 给对象lv_clock.weekday_label添加样式

    // 设置时间标签lv_clock.time_label对象基于父对象居中对齐
    lv_obj_align_to(lv_clock.time_label, lv_obj_get_parent(lv_clock.time_label), LV_ALIGN_CENTER, 0, 0);
     // 设置时间标签lv_clock.date_label对象基于父对象顶部中间对齐
    lv_obj_align_to(lv_clock.date_label, lv_obj_get_parent(lv_clock.date_label), LV_ALIGN_TOP_MID, 2, 0);
    // 设置时间标签lv_clock.weekday_label对象基于父对象底部中间对齐
    lv_obj_align_to(lv_clock.weekday_label, lv_obj_get_parent(lv_clock.weekday_label), LV_ALIGN_BOTTOM_MID, -2, 0);

    lv_timer_t* task_timer = lv_timer_create(clock_date_task_callback, 200, (void *)&lv_clock); // 创建定时任务，200ms刷新一次
    if (task_timer == NULL)
    {
        printf("[%s:%d] lv_timer_create failed\n", __FUNCTION__, __LINE__);
    }
    /**********************
     *   create back button
     **********************/
    lv_obj_t * backBtn = lv_btn_create(watchScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,watchBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");
    lv_obj_align(backToFirstBtnLabel,LV_ALIGN_CENTER,0,0);
}

static void pageThree(void)
{
    /**********************
     *   机器编号字体样式
     **********************/

    MacStyleFont=&lv_font_montserrat_12;
    lv_style_set_text_font(&MacStyle,MacStyleFont);
    lv_style_set_text_color(&MacStyle,lv_color_black());

    /**********************
     *   help按钮样式
     **********************/
     lv_style_reset(&helpBtnStyle);
     lv_style_init(&helpBtnStyle);
     lv_style_set_radius(&helpBtnStyle, LV_RADIUS_CIRCLE); // 设置按钮样式圆角弧度
     lv_style_set_bg_opa(&helpBtnStyle, LV_OPA_0); // 设置背景的透明度
     lv_style_set_border_opa(&helpBtnStyle,LV_OPA_0);  //设置边界透明度
     lv_style_set_border_width(&helpBtnStyle,0);
     lv_style_set_size(&helpBtnStyle,LV_SIZE_CONTENT);

    /**********************
     *   支付界面字体样式
     **********************/

    bigNameFont=&lv_font_montserrat_44;
    bigPriceFont=&lv_font_montserrat_48;

    lv_style_set_text_font(&bigNameStyle,bigNameFont);
    lv_style_set_text_font(&bigPriceStyle,bigPriceFont);
    lv_style_set_text_color(&bigNameStyle,lv_color_white());
    lv_style_set_text_color(&bigPriceStyle,lv_color_white());

    /**********************
     *   page3屏幕背景样式
     **********************/
    lv_style_init(&shopScreenStyle);          //初始化style
    lv_style_set_radius(&shopScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&shopScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&shopScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    shopScreen=lv_obj_create(screen);
    lv_obj_align(shopScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(shopScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(shopScreen,&shopScreenStyle,0);

    lv_obj_t* img_bandAid=lv_img_create(shopScreen);
    lv_img_set_src(img_bandAid,&bandAid);
    lv_obj_t* img_brush=lv_img_create(shopScreen);
    lv_img_set_src(img_brush,&brush);
    lv_obj_t* img_mask=lv_img_create(shopScreen);
    lv_img_set_src(img_mask,&mask);
    lv_obj_t* img_noteBook=lv_img_create(shopScreen);
    lv_img_set_src(img_noteBook,&notebook);
    lv_obj_t* img_recycleBag=lv_img_create(shopScreen);
    lv_img_set_src(img_recycleBag,&recycle_bag);
    lv_obj_t* img_rubbishBag=lv_img_create(shopScreen);
    lv_img_set_src(img_rubbishBag,&rubbishBag);
    lv_obj_t* img_straw=lv_img_create(shopScreen);
    lv_img_set_src(img_straw,&straw);
    lv_obj_t* img_tableWare=lv_img_create(shopScreen);
    lv_img_set_src(img_tableWare,&tableware);
    lv_obj_t* img_wetWipe=lv_img_create(shopScreen);
    lv_img_set_src(img_wetWipe,&wet_wipe);

    lv_obj_set_pos(img_bandAid,50,50);
    lv_obj_set_pos(img_brush,500,50);
    lv_obj_set_pos(img_mask,950,50);
    lv_obj_set_pos(img_noteBook,50,350);
    lv_obj_set_pos(img_recycleBag,500,350);
    lv_obj_set_pos(img_rubbishBag,950,350);
    lv_obj_set_pos(img_straw,50,650);
    lv_obj_set_pos(img_tableWare,500,650);
    lv_obj_set_pos(img_wetWipe,950,650);

    lv_obj_t * backBtn = lv_btn_create(shopScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,shopBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");



    nameFont=&lv_font_montserrat_16;
    priceFont=&lv_font_montserrat_18;
    buyLabelFont=&lv_font_montserrat_20;
    lv_style_set_text_font(&nameStyle,nameFont);
    lv_style_set_text_font(&priceStyle,priceFont);
    lv_style_set_text_font(&buyLabelStyle,buyLabelFont);
    lv_style_set_text_color(&nameStyle,lv_color_white());
    lv_style_set_text_color(&priceStyle,lv_color_white());
    lv_style_set_text_color(&buyLabelStyle,lv_color_white());

    lv_obj_t * nameLabel1 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel1,&nameStyle,0 );
    lv_label_set_text(nameLabel1,"bandAid");
    lv_obj_set_pos(nameLabel1,200,50);
    lv_obj_t * priceLabel1 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel1,&priceStyle,0);
    lv_label_set_text(priceLabel1,"1 yuan");
    lv_obj_set_pos(priceLabel1,200,80);
    lv_obj_t * buyBtn1=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn1,LV_SIZE_CONTENT); //自适应高度
    lv_obj_add_event_cb(buyBtn1,bandAidBuyCB,LV_EVENT_ALL,NULL);
    lv_obj_t * buyLabel1 = lv_label_create(buyBtn1);
    lv_obj_add_style(buyLabel1,&buyLabelStyle,0);
    lv_label_set_text(buyLabel1,"Buy");
    lv_obj_set_pos(buyBtn1,180,110);

    lv_obj_t * nameLabel2 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel2,&nameStyle,0 );
    lv_label_set_text(nameLabel2,"brush");
    lv_obj_set_pos(nameLabel2,650,50);
    lv_obj_t * priceLabel2 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel2,&priceStyle,0);
    lv_label_set_text(priceLabel2,"10 yuan");
    lv_obj_set_pos(priceLabel2,650,80);
    lv_obj_t * buyBtn2=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn2,LV_SIZE_CONTENT); //自适应高度
    lv_obj_t * buyLabel2 = lv_label_create(buyBtn2);
    lv_obj_add_style(buyLabel2,&buyLabelStyle,0);
    lv_obj_add_event_cb(buyBtn2,brushBuyCB,LV_EVENT_ALL,NULL);
    lv_label_set_text(buyLabel2,"Buy");
    lv_obj_set_pos(buyBtn2,630,110);

    lv_obj_t * nameLabel3 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel3,&nameStyle,0 );
    lv_label_set_text(nameLabel3,"mask");
    lv_obj_set_pos(nameLabel3,1200,50);
    lv_obj_t * priceLabel3 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel3,&priceStyle,0);
    lv_label_set_text(priceLabel3,"5 yuan");
    lv_obj_set_pos(priceLabel3,1200,80);
    lv_obj_t * buyBtn3=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn3,LV_SIZE_CONTENT); //自适应高度
    lv_obj_t * buyLabel3 = lv_label_create(buyBtn3);
    lv_obj_add_style(buyLabel3,&buyLabelStyle,0);
    lv_label_set_text(buyLabel3,"Buy");
    lv_obj_set_pos(buyBtn3,1180,110);
    lv_obj_add_event_cb(buyBtn3,maskBuyCB,LV_EVENT_ALL,NULL);

    lv_obj_t * nameLabel4 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel4,&nameStyle,0 );
    lv_label_set_text(nameLabel4,"notebook");
    lv_obj_set_pos(nameLabel4,200,350);
    lv_obj_t * priceLabel4 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel4,&priceStyle,0);
    lv_label_set_text(priceLabel4,"10 yuan");
    lv_obj_set_pos(priceLabel4,200,380);
    lv_obj_t * buyBtn4=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn4,LV_SIZE_CONTENT); //自适应高度
    lv_obj_add_event_cb(buyBtn4,notebookBuyCB,LV_EVENT_ALL,NULL);
    lv_obj_t * buyLabel4 = lv_label_create(buyBtn4);
    lv_obj_add_style(buyLabel4,&buyLabelStyle,0);
    lv_label_set_text(buyLabel4,"Buy");
    lv_obj_set_pos(buyBtn4,180,410);

    lv_obj_t * nameLabel5 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel5,&nameStyle,0 );
    lv_label_set_text(nameLabel5,"recycle bag");
    lv_obj_set_pos(nameLabel5,700,350);
    lv_obj_t * priceLabel5 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel5,&priceStyle,0);
    lv_label_set_text(priceLabel5,"2 yuan");
    lv_obj_set_pos(priceLabel5,700,380);
    lv_obj_t * buyBtn5=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn5,LV_SIZE_CONTENT); //自适应高度
    lv_obj_t * buyLabel5 = lv_label_create(buyBtn5);
    lv_obj_add_style(buyLabel5,&buyLabelStyle,0);
    lv_label_set_text(buyLabel5,"Buy");
    lv_obj_set_pos(buyBtn5,680,410);
    lv_obj_add_event_cb(buyBtn5,recyclebagBuyCB,LV_EVENT_ALL,NULL);

    lv_obj_t * nameLabel6 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel6,&nameStyle,0 );
    lv_label_set_text(nameLabel6,"rubbish bag");
    lv_obj_set_pos(nameLabel6,1200,350);
    lv_obj_t * priceLabel6 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel6,&priceStyle,0);
    lv_label_set_text(priceLabel6,"4 yuan");
    lv_obj_set_pos(priceLabel6,1200,380);
    lv_obj_t * buyBtn6=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn6,LV_SIZE_CONTENT); //自适应高度
    lv_obj_t * buyLabel6 = lv_label_create(buyBtn6);
    lv_obj_add_style(buyLabel6,&buyLabelStyle,0);
    lv_label_set_text(buyLabel6,"Buy");
    lv_obj_set_pos(buyBtn6,1180,410);
    lv_obj_add_event_cb(buyBtn6,rubbishBagBuyCB,LV_EVENT_ALL,NULL);

    lv_obj_t * nameLabel7 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel7,&nameStyle,0 );
    lv_label_set_text(nameLabel7,"straw");
    lv_obj_set_pos(nameLabel7,200,650);
    lv_obj_t * priceLabel7 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel7,&priceStyle,0);
    lv_label_set_text(priceLabel7,"1 yuan");
    lv_obj_set_pos(priceLabel7,200,680);
    lv_obj_t * buyBtn7=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn7,LV_SIZE_CONTENT); //自适应高度
    lv_obj_t * buyLabel7 = lv_label_create(buyBtn7);
    lv_obj_add_style(buyLabel7,&buyLabelStyle,0);
    lv_label_set_text(buyLabel7,"Buy");
    lv_obj_set_pos(buyBtn7,180,710);
    lv_obj_add_event_cb(buyBtn7,strawBuyCB,LV_EVENT_ALL,NULL);

    lv_obj_t * nameLabel8 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel8,&nameStyle,0 );
    lv_label_set_text(nameLabel8,"tableware");
    lv_obj_set_pos(nameLabel8,700,650);
    lv_obj_t * priceLabel8 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel8,&priceStyle,0);
    lv_label_set_text(priceLabel8,"20 yuan");
    lv_obj_set_pos(priceLabel8,700,680);
    lv_obj_t * buyBtn8=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn8,LV_SIZE_CONTENT); //自适应高度
    lv_obj_t * buyLabel8 = lv_label_create(buyBtn8);
    lv_obj_add_style(buyLabel8,&buyLabelStyle,0);
    lv_label_set_text(buyLabel8,"Buy");
    lv_obj_set_pos(buyBtn8,680,710);
    lv_obj_add_event_cb(buyBtn8,tablewareBuyCB,LV_EVENT_ALL,NULL);

    lv_obj_t * nameLabel9 = lv_label_create(shopScreen);
    lv_obj_add_style(nameLabel9,&nameStyle,0 );
    lv_label_set_text(nameLabel9,"wet wipe");
    lv_obj_set_pos(nameLabel9,1200,650);
    lv_obj_t * priceLabel9 = lv_label_create(shopScreen);
    lv_obj_add_style(priceLabel9,&priceStyle,0);
    lv_label_set_text(priceLabel9,"7 yuan");
    lv_obj_set_pos(priceLabel9,1200,680);
    lv_obj_t * buyBtn9=lv_btn_create(shopScreen);
    lv_obj_set_height(buyBtn9,LV_SIZE_CONTENT); //自适应高度
    lv_obj_t * buyLabel9 = lv_label_create(buyBtn9);
    lv_obj_add_style(buyLabel9,&buyLabelStyle,0);
    lv_label_set_text(buyLabel9,"Buy");
    lv_obj_set_pos(buyBtn9,1180,710);
    lv_obj_add_event_cb(buyBtn9,wetwipeBuyCB,LV_EVENT_ALL,NULL);

    lv_obj_t * Mac = lv_label_create(shopScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(shopScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);
    lv_obj_add_event_cb(helpBtn,helpBtnCB,LV_EVENT_ALL,NULL);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);





}

static void pageBandAid(void)
{
    /**********************
     *   page-创口贴支付 屏幕背景样式
     **********************/
    lv_style_init(&bandAidBuyScreenStyle);          //初始化style
    lv_style_set_radius(&bandAidBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&bandAidBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&bandAidBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    bandAidBuyScreen=lv_obj_create(screen);
    lv_obj_align(bandAidBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(bandAidBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(bandAidBuyScreen,&bandAidBuyScreenStyle,0);

    lv_obj_t * img_bigBandAid = lv_img_create(bandAidBuyScreen);
    lv_img_set_src(img_bigBandAid,&bigBandAid);
    lv_obj_set_pos(img_bigBandAid,200,50);

    lv_obj_t * nameLabel = lv_label_create(bandAidBuyScreen);
    lv_obj_add_style(nameLabel,&bigNameStyle,0);
    lv_label_set_text(nameLabel,"bandAid");
    lv_obj_set_pos(nameLabel,800,150);

    lv_obj_t * priceLabel = lv_label_create(bandAidBuyScreen);
    lv_obj_add_style(priceLabel,&bigPriceStyle,0);
    lv_label_set_text(priceLabel,"1 yuan");
    lv_obj_set_pos(priceLabel,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(bandAidBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(bandAidBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(bandAidBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(bandAidBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,bandAidBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");


//    lv_timer_set_repeat_count(countdownTime, 5);

}


static void pageBrush(void)
{
    /**********************
     *   page-牙刷支付 屏幕背景样式
     **********************/
    lv_style_init(&brushBuyScreenStyle);          //初始化style
    lv_style_set_radius(&brushBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&brushBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&brushBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    brushBuyScreen=lv_obj_create(screen);
    lv_obj_align(brushBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(brushBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(brushBuyScreen,&brushBuyScreenStyle,0);


    lv_obj_t * img_bigBrush = lv_img_create(brushBuyScreen);
    lv_img_set_src(img_bigBrush,&bigBrush);
    lv_obj_set_pos(img_bigBrush,200,30);

    lv_obj_t * nameLabe2 = lv_label_create(brushBuyScreen);
    lv_obj_add_style(nameLabe2,&bigNameStyle,0);
    lv_label_set_text(nameLabe2,"brush");
    lv_obj_set_pos(nameLabe2,800,150);

    lv_obj_t * priceLabe2 = lv_label_create(brushBuyScreen);
    lv_obj_add_style(priceLabe2,&bigPriceStyle,0);
    lv_label_set_text(priceLabe2,"10 yuan");
    lv_obj_set_pos(priceLabe2,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(brushBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(brushBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(brushBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(brushBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,brushBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");



}

static void pageMask(void)
{
    /**********************
     *   page-口罩支付 屏幕背景样式
     **********************/
    lv_style_init(&maskBuyScreenStyle);          //初始化style
    lv_style_set_radius(&maskBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&maskBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&maskBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    maskBuyScreen=lv_obj_create(screen);
    lv_obj_align(maskBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(maskBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(maskBuyScreen,&maskBuyScreenStyle,0);

    lv_obj_t * img_mask = lv_img_create(maskBuyScreen);
    lv_img_set_src(img_mask,&big_mask);
    lv_obj_set_pos(img_mask,200,150);

    lv_obj_t * nameLabe3 = lv_label_create(maskBuyScreen);
    lv_obj_add_style(nameLabe3,&bigNameStyle,0);
    lv_label_set_text(nameLabe3,"mask");
    lv_obj_set_pos(nameLabe3,800,150);

    lv_obj_t * priceLabe3 = lv_label_create(maskBuyScreen);
    lv_obj_add_style(priceLabe3,&bigPriceStyle,0);
    lv_label_set_text(priceLabe3,"5 yuan");
    lv_obj_set_pos(priceLabe3,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(maskBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(maskBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(maskBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(maskBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,maskBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");



}

static void pageNotebook(void)
{
    /**********************
     *   page-笔记本支付 屏幕背景样式
     **********************/
    lv_style_init(&noteBookBuyScreenStyle);          //初始化style
    lv_style_set_radius(&noteBookBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&noteBookBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&noteBookBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    noteBookBuyScreen=lv_obj_create(screen);
    lv_obj_align(noteBookBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(noteBookBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(noteBookBuyScreen,&noteBookBuyScreenStyle,0);

    lv_obj_t * img_notebook = lv_img_create(noteBookBuyScreen);
    lv_img_set_src(img_notebook,&bigNotebook);
    lv_obj_set_pos(img_notebook,200,50);

    lv_obj_t * nameLabel4 = lv_label_create(noteBookBuyScreen);
    lv_obj_add_style(nameLabel4,&bigNameStyle,0);
    lv_label_set_text(nameLabel4,"notebook");
    lv_obj_set_pos(nameLabel4,800,150);

    lv_obj_t * priceLabel4 = lv_label_create(noteBookBuyScreen);
    lv_obj_add_style(priceLabel4,&bigPriceStyle,0);
    lv_label_set_text(priceLabel4,"10 yuan");
    lv_obj_set_pos(priceLabel4,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(noteBookBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(noteBookBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(noteBookBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(noteBookBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,notebookBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");



}

static void pageRecyclebag(void)
{
    /**********************
     *   page-可回收纸袋支付 屏幕背景样式
     **********************/
    lv_style_init(&recyclebagBuyScreenStyle);          //初始化style
    lv_style_set_radius(&recyclebagBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&recyclebagBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&recyclebagBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    recyclebagBuyScreen=lv_obj_create(screen);
    lv_obj_align(recyclebagBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(recyclebagBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(recyclebagBuyScreen,&recyclebagBuyScreenStyle,0);

    lv_obj_t * img_recyclebag = lv_img_create(recyclebagBuyScreen);
    lv_img_set_src(img_recyclebag,&big_recycle_bag);
    lv_obj_set_pos(img_recyclebag,200,80);

    lv_obj_t * nameLabel5 = lv_label_create(recyclebagBuyScreen);
    lv_obj_add_style(nameLabel5,&bigNameStyle,0);
    lv_label_set_text(nameLabel5,"recycle bag");
    lv_obj_set_pos(nameLabel5,800,150);

    lv_obj_t * priceLabel5 = lv_label_create(recyclebagBuyScreen);
    lv_obj_add_style(priceLabel5,&bigPriceStyle,0);
    lv_label_set_text(priceLabel5,"2 yuan");
    lv_obj_set_pos(priceLabel5,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(recyclebagBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(recyclebagBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(recyclebagBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(recyclebagBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,recyclebagBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");



}

static void pageRubbishbag(void)
{
    /**********************
     *   page-可回收垃圾袋支付 屏幕背景样式
     **********************/
    lv_style_init(&rubbishBagBuyScreenStyle);          //初始化style
    lv_style_set_radius(&rubbishBagBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&rubbishBagBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&rubbishBagBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    rubbishBagBuyScreen=lv_obj_create(screen);
    lv_obj_align(rubbishBagBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(rubbishBagBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(rubbishBagBuyScreen,&rubbishBagBuyScreenStyle,0);

    lv_obj_t * img_rubbishbag = lv_img_create(rubbishBagBuyScreen);
    lv_img_set_src(img_rubbishbag,&bigrubbishBag);
    lv_obj_set_pos(img_rubbishbag,200,50);

    lv_obj_t * nameLabel6 = lv_label_create(rubbishBagBuyScreen);
    lv_obj_add_style(nameLabel6,&bigNameStyle,0);
    lv_label_set_text(nameLabel6,"rubbish bag");
    lv_obj_set_pos(nameLabel6,800,150);

    lv_obj_t * priceLabel6 = lv_label_create(rubbishBagBuyScreen);
    lv_obj_add_style(priceLabel6,&bigPriceStyle,0);
    lv_label_set_text(priceLabel6,"4 yuan");
    lv_obj_set_pos(priceLabel6,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(rubbishBagBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(rubbishBagBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(rubbishBagBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(rubbishBagBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,rubbishBagBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");



}

static void pageStraw(void)
{
    /**********************
     *   page-生物可降解吸管支付 屏幕背景样式
     **********************/
    lv_style_init(&strawBuyScreenStyle);          //初始化style
    lv_style_set_radius(&strawBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&strawBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&strawBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    strawBuyScreen=lv_obj_create(screen);
    lv_obj_align(strawBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(strawBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(strawBuyScreen,&strawBuyScreenStyle,0);


    lv_obj_t * img_straw = lv_img_create(strawBuyScreen);
    lv_img_set_src(img_straw,&bigStraw);
    lv_obj_set_pos(img_straw,200,50);

    lv_obj_t * nameLabel7 = lv_label_create(strawBuyScreen);
    lv_obj_add_style(nameLabel7,&bigNameStyle,0);
    lv_label_set_text(nameLabel7,"straw");
    lv_obj_set_pos(nameLabel7,800,150);

    lv_obj_t * priceLabel7 = lv_label_create(strawBuyScreen);
    lv_obj_add_style(priceLabel7,&bigPriceStyle,0);
    lv_label_set_text(priceLabel7,"1 yuan");
    lv_obj_set_pos(priceLabel7,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(strawBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(strawBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(strawBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(strawBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,strawBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");



}




static void pageTableware(void)
{
    /**********************
     *   page-可生物降解餐具支付 屏幕背景样式
     **********************/
    lv_style_init(&tablewareBuyScreenStyle);          //初始化style
    lv_style_set_radius(&tablewareBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&tablewareBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&tablewareBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    tablewareBuyScreen=lv_obj_create(screen);
    lv_obj_align(tablewareBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(tablewareBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(tablewareBuyScreen,&tablewareBuyScreenStyle,0);

    lv_obj_t * img_tableware = lv_img_create(tablewareBuyScreen);
    lv_img_set_src(img_tableware,&bigTableware);
    lv_obj_set_pos(img_tableware,200,100);

    lv_obj_t * nameLabel8 = lv_label_create(tablewareBuyScreen);
    lv_obj_add_style(nameLabel8,&bigNameStyle,0);
    lv_label_set_text(nameLabel8,"tableware");
    lv_obj_set_pos(nameLabel8,800,150);

    lv_obj_t * priceLabel8 = lv_label_create(tablewareBuyScreen);
    lv_obj_add_style(priceLabel8,&bigPriceStyle,0);
    lv_label_set_text(priceLabel8,"20 yuan");
    lv_obj_set_pos(priceLabel8,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(tablewareBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(tablewareBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(tablewareBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(tablewareBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,tablewareBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");



}

static void pageWetWipe(void)
{
    /**********************
     *   page-湿巾支付 屏幕背景样式
     **********************/
    lv_style_init(&wetwipeBuyScreenStyle);          //初始化style
    lv_style_set_radius(&wetwipeBuyScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&wetwipeBuyScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&wetwipeBuyScreenStyle,lv_palette_main(LV_PALETTE_LIGHT_BLUE)); //蓝色背景色

    wetwipeBuyScreen=lv_obj_create(screen);
    lv_obj_align(wetwipeBuyScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(wetwipeBuyScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(wetwipeBuyScreen,&wetwipeBuyScreenStyle,0);

    lv_obj_t * img_wet_wipe = lv_img_create(wetwipeBuyScreen);
    lv_img_set_src(img_wet_wipe,&big_wet_wipe);
    lv_obj_set_pos(img_wet_wipe,200,100);

    lv_obj_t * nameLabel9 = lv_label_create(wetwipeBuyScreen);
    lv_obj_add_style(nameLabel9,&bigNameStyle,0);
    lv_label_set_text(nameLabel9,"wet wipe");
    lv_obj_set_pos(nameLabel9,800,150);

    lv_obj_t * priceLabel9 = lv_label_create(wetwipeBuyScreen);
    lv_obj_add_style(priceLabel9,&bigPriceStyle,0);
    lv_label_set_text(priceLabel9,"7 yuan");
    lv_obj_set_pos(priceLabel9,800,350);

    /*Create a 100x100 QR code*/
	lv_obj_t * qr = lv_qrcode_create(wetwipeBuyScreen, 300, lv_color_black(), lv_color_white());

	/*Set data*/
	lv_qrcode_update(qr, data, strlen(data));

	lv_obj_set_pos(qr,1040,130);

    lv_obj_t * Mac = lv_label_create(wetwipeBuyScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

    lv_obj_t * helpBtn = lv_btn_create(wetwipeBuyScreen);
    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);

    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
    lv_img_set_src(img_helpSign,&helpSign);
    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);

    lv_obj_t * backBtn = lv_btn_create(wetwipeBuyScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,wetwipeBackCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");


}



static void pageHelp(void)
{
    /**********************
     *   page-help屏幕背景样式
     **********************/
    lv_style_init(&helpScreenStyle);          //初始化style
    lv_style_set_radius(&helpScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&helpScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&helpScreenStyle,lv_palette_main(LV_PALETTE_GREY)); //灰色背景色

    helpScreen=lv_obj_create(screen);
    lv_obj_align(helpScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(helpScreen,lv_pct(100),lv_pct(100));

    /**********************
     *   help界面字体样式
     **********************/

    helpContentFont=&lv_font_montserrat_20;
    lv_style_set_text_font(&helpContentStyle,helpContentFont);
    lv_style_set_text_color(&helpContentStyle,lv_color_white());


    /**********************
     *   create 1st panel
     **********************/
     lv_obj_t * panel1 = lv_obj_create(helpScreen);
     lv_obj_set_size(panel1,lv_pct(60),LV_SIZE_CONTENT);
     lv_obj_add_style(panel1,&helpScreenStyle,0);

     lv_obj_t * label1 = lv_label_create(panel1);
     lv_obj_add_style(label1,&helpContentStyle,0);
     lv_label_set_text(label1,"1.Shopping process: Click the screen to enter the shopping interface,\
                       \nclick the buy button to enter the payment interface, support wechat and Alipay\
                       \nscan code payment, you can get the product after payment.");

    /**********************
     *   create 2nd panel
     **********************/
     lv_obj_t * panel2 = lv_obj_create(helpScreen);
     lv_obj_set_size(panel2,lv_pct(60),LV_SIZE_CONTENT);
     lv_obj_add_style(panel2,&helpScreenStyle,0);

     lv_obj_t * label2 = lv_label_create(panel2);
     lv_obj_add_style(label2,&helpContentStyle,0);
     lv_label_set_text(label2,"2.If you encounter any trouble during operation, please call: 000-6666.") ;


     /**********************
     *   create 3rd panel
     **********************/
     lv_obj_t * panel3 = lv_obj_create(helpScreen);
     lv_obj_set_size(panel3,lv_pct(60),LV_SIZE_CONTENT);
     lv_obj_add_style(panel3,&helpScreenStyle,0);

     lv_obj_t * label3 = lv_label_create(panel3);
     lv_obj_add_style(label3,&helpContentStyle,0);
     lv_label_set_text(label3,"3.Enjoy your shopping!") ;


     /**********************
     *   create 4th panel
     **********************/
     lv_obj_t * panel4 = lv_obj_create(helpScreen);
     lv_obj_set_size(panel4,LV_SIZE_CONTENT,LV_SIZE_CONTENT);

     lv_obj_t * img_Help = lv_img_create(panel4);
     lv_img_set_src(img_Help,&help);


     /**********************
     *   create back button
     **********************/
    lv_obj_t * backBtn = lv_btn_create(helpScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_add_event_cb(backBtn,helpBackBtnCB,LV_EVENT_ALL,NULL);
//    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);


    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");
    lv_obj_align(backToFirstBtnLabel,LV_ALIGN_CENTER,0,0);


     /**********************
     *   Grid
     **********************/
     static lv_coord_t grid_main_col_dsc[]={LV_GRID_FR(2),LV_GRID_FR(3),LV_GRID_TEMPLATE_LAST};
     static lv_coord_t grid_main_row_dsc[]={LV_GRID_FR(1),LV_GRID_FR(1),LV_GRID_FR(1),LV_GRID_TEMPLATE_LAST};
     lv_obj_set_grid_dsc_array(helpScreen,grid_main_col_dsc,grid_main_row_dsc);
     lv_obj_set_grid_cell(panel4,LV_GRID_ALIGN_STRETCH,0,1,LV_GRID_ALIGN_CENTER,0,2);
     lv_obj_set_grid_cell(panel1,LV_GRID_ALIGN_STRETCH,1,1,LV_GRID_ALIGN_CENTER,0,1);
     lv_obj_set_grid_cell(panel2,LV_GRID_ALIGN_STRETCH,1,1,LV_GRID_ALIGN_CENTER,1,1);
     lv_obj_set_grid_cell(panel3,LV_GRID_ALIGN_STRETCH,1,1,LV_GRID_ALIGN_CENTER,2,1);
     lv_obj_set_grid_cell(backBtn,LV_GRID_ALIGN_STRETCH,0,1,LV_GRID_ALIGN_CENTER,2,1);

}



static void pagePaySuccess(void)
{
    /**********************
     *   page-支付成功 屏幕背景样式
     **********************/
    lv_style_init(&paySuccessScreenStyle);          //初始化style
    lv_style_set_radius(&paySuccessScreenStyle,5);  //设置样式的圆角
    lv_style_set_bg_opa(&paySuccessScreenStyle,LV_OPA_COVER);  //不透明
    lv_style_set_bg_color(&paySuccessScreenStyle,lv_palette_main(LV_PALETTE_GREY)); //灰色背景色

    paySuccessScreen=lv_obj_create(screen);
    lv_obj_align(paySuccessScreen,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(paySuccessScreen,lv_pct(100),lv_pct(100));
    lv_obj_add_style(paySuccessScreen,&paySuccessScreenStyle,0);


    /**********************
     *   支付成功界面倒计时字体样式
     **********************/

    countdownStyleFont=&lv_font_montserrat_18;
    lv_style_set_text_font(&countdownStyle,countdownStyleFont);
    lv_style_set_text_color(&countdownStyle,lv_palette_main(LV_PALETTE_DEEP_PURPLE));

    /**********************
     *   支付成功界面标签字体样式
     **********************/

    paySuccessLabelStyleFont=&lv_font_montserrat_28;
    lv_style_set_text_font(&paySuccessLabelStyle,paySuccessLabelStyleFont);
    lv_style_set_text_color(&paySuccessLabelStyle,lv_palette_main(LV_PALETTE_DEEP_ORANGE));


    /**********************
     *   支付成功界面返回按钮样式
     **********************/
     lv_style_reset(&backToFirstBtnStyle);
     lv_style_init(&backToFirstBtnStyle);
     lv_style_set_radius(&backToFirstBtnStyle, 10); // 设置按钮样式圆角弧度
     lv_style_set_bg_opa(&backToFirstBtnStyle, LV_OPA_COVER); // 设置背景的透明度
     lv_style_set_bg_color(&backToFirstBtnStyle, lv_palette_lighten(LV_PALETTE_RED, 3)); // 设置背景的颜色为淡红色

     backToFirstBtnLabelStyleFont=&lv_font_montserrat_28;
     lv_style_set_text_font(&backToFirstBtnLabelStyle,backToFirstBtnLabelStyleFont);
     lv_style_set_text_color(&backToFirstBtnLabelStyle,lv_color_white());


    lv_obj_t * img_PaySuccess = lv_img_create(paySuccessScreen);
    lv_img_set_src(img_PaySuccess,&paySuccess);
    lv_obj_align(img_PaySuccess,LV_ALIGN_CENTER,0,0);


    countdownLabel = lv_label_create(paySuccessScreen);
    lv_obj_add_style(countdownLabel,&countdownStyle,0);
    lv_label_set_text_fmt(countdownLabel,"%u",countdown1);
    lv_obj_align(countdownLabel,LV_ALIGN_BOTTOM_MID,0,0);

    lv_obj_t * paySuccessLabel = lv_label_create(paySuccessScreen);
    lv_obj_add_style(paySuccessLabel,&paySuccessLabelStyle,0);
    lv_label_set_text(paySuccessLabel,"PAY SUCCESSFULLY!");
    lv_obj_align(paySuccessLabel,LV_ALIGN_BOTTOM_MID,0,-50);


    lv_obj_t * backBtn = lv_btn_create(paySuccessScreen);
    lv_obj_add_style(backBtn,&backToFirstBtnStyle,0);
    lv_obj_align(backBtn,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(backBtn,paySuccessBackBtnCB,LV_EVENT_ALL,NULL);

    lv_obj_t * backToFirstBtnLabel = lv_label_create(backBtn);
    lv_obj_add_style(backToFirstBtnLabel,&backToFirstBtnLabelStyle,0);
    lv_label_set_text(backToFirstBtnLabel,"back");





    lv_obj_t * Mac = lv_label_create(paySuccessScreen);
    lv_obj_add_style(Mac,&MacStyle,0);
    lv_label_set_text(Mac,"Bjtu-000-001");
    lv_obj_set_pos(Mac,0,0);

//    lv_obj_t * helpBtn = lv_btn_create(paySuccessScreen);
//    lv_obj_add_style(helpBtn,&helpBtnStyle,0);
//    lv_obj_align(helpBtn,LV_ALIGN_TOP_RIGHT,0,0);
//
//    lv_obj_t * img_helpSign = lv_img_create(helpBtn);
//    lv_img_set_src(img_helpSign,&helpSign);
//    lv_obj_align(img_helpSign,LV_ALIGN_CENTER,0,0);





}



/**********************
 *   GLOBAL FUNCTIONS
 **********************/
 void lv_bjtu_achive(void)
 {
    screen = lv_scr_act();


	pageOne();
	pageTwo();
	pageThree();
	pageBandAid();
	pageBrush();
	pageMask();
	pageNotebook();
	pageRecyclebag();
	pageRubbishbag();
	pageStraw();
	pageTableware();
	pageWetWipe();
	pageHelp();
	pagePaySuccess();


	/**********************
     *   隐藏其余界面，只显示第一张界面
     **********************/
       lv_obj_add_flag(watchScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(shopScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(bandAidBuyScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(brushBuyScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(helpScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(maskBuyScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(noteBookBuyScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(paySuccessScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(recyclebagBuyScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(rubbishBagBuyScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(strawBuyScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(tablewareBuyScreen,LV_OBJ_FLAG_HIDDEN);
       lv_obj_add_flag(wetwipeBuyScreen,LV_OBJ_FLAG_HIDDEN);
//     lv_obj_add_flag(videoScreen,LV_OBJ_FLAG_HIDDEN);

 }
#endif







