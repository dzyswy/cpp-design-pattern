#include "menu_component.h"





int main(int argc, char* argv[])
{
    google::InstallFailureSignalHandler();
    google::InitGoogleLogging(argv[0]);

    FLAGS_stderrthreshold = 0;
    FLAGS_minloglevel = 0;


    MenuBar root("root");
    MenuBar bar_ae("AE");
    MenuItem item_exp_time("exp_time");
    MenuItem item_ae_gain("ae_gain");
    bar_ae.add_child(&item_exp_time);
    bar_ae.add_child(&item_ae_gain);
    MenuBar bar_ccm("CCM");
    MenuItem item_ccm0("ccm0"); 
    MenuItem item_ccm1("ccm1");
    MenuItem item_ccm2("ccm2");
    bar_ccm.add_child(&item_ccm0);
    bar_ccm.add_child(&item_ccm1);
    bar_ccm.add_child(&item_ccm2);
    MenuBar bar_awb("AWB");
    MenuItem item_awb_rgain("awb_rgain");
    MenuItem item_awb_ggain("awb_ggain");
    MenuItem item_awb_bgain("awb_bgain");
    bar_awb.add_child(&bar_ccm);
    bar_awb.add_child(&item_awb_rgain);
    bar_awb.add_child(&item_awb_ggain);
    bar_awb.add_child(&item_awb_bgain);
    root.add_child(&bar_ae);
    root.add_child(&bar_awb);
    

    root.show();

    MenuManager xmenu(&root);

    std::cout << "wait key, q is quit ..." << std::endl;
    while(1)
    {
        
        char key = std::getchar();
        if (key == 'q') {
            break;
        }
        else if (key == 'w') {
            std::cout << "menu inc" << std::endl;
            xmenu.menu_inc();
        }
        else if (key == 's') {
            std::cout << "menu dec" << std::endl;
            xmenu.menu_dec();
        }
        else if (key == 'a') {
            std::cout << "menu left" << std::endl;
            xmenu.menu_left();
        }
        else if (key == 'd') {
            std::cout << "menu right" << std::endl;
            xmenu.menu_right();
        }
        else if (key == ' ') {
            std::cout << "menu ok" << std::endl;
            xmenu.menu_ok();
        }
        else if (key == 'b') {
            std::cout << "menu cancel" << std::endl;
            xmenu.menu_cancel();
        }
        std::cout << "hot: " << xmenu.hot_item_name() << std::endl;
    }
     


    std::cout << "bye!" << std::endl;

    return 0;
}








