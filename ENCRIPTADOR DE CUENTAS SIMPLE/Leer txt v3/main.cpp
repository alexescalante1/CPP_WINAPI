#include <iostream>
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <fstream>
#include "resource.h"

using namespace std;

HINSTANCE hInst;
HBRUSH brushBlack;
HBRUSH brushWhite;
HPEN greenPen;
COLORREF actual;

bool UNA_VEZ=1;
string INS_AP[3];
string INS_CT[15];
string Encriptado[95][2];
char ENTRADA_C[99999];

void DATOS_DE_ENCRIPTADO()
{
    int j = 0;for(char m=' ';m<='}';m++,j++){
        Encriptado[j][1]=m;
    }
    Encriptado[0][0] = "wq2e1q2wr2ewrtewtwe2r2ew1r2ew1r4ew6r256ew4rw5et";
    Encriptado[1][0] = "gh2j6g3hh63ghj62h6hgk62hm3bnm625hujm26hj5kmjgh2";
    Encriptado[2][0] = "ngf54n5g4h5f44hu7ty4hjgf4hn5fg4b5h4fg5h4gf4j7hg";
    Encriptado[3][0] = "pi6o5p5oi5ip68oi58p5o85p8o5ip685oi865p86o5i8p5o";
    Encriptado[4][0] = "g9hgf8j9gfh99gfh9gf8h9gf8h9gfhdfgsretytjn9bvvvb";
    Encriptado[5][0] = "rtu88tyu88hd8f9gdf9g8dfhf8d7h8dfhd48fg8df8h4d8f";
    Encriptado[6][0] = "qw9e9qw98e8qw8d9sd8s89f98ds8gfdfghf89j89ghj8gh9";
    Encriptado[7][0] = "ddsfd4s85fdfgdfhifdjgijfdijgijfdughfdhguhfudghu";
    Encriptado[8][0] = "qwewqe5d4sa4d5sd44s4da5s4dasf4a5s6das666ad56sd6";
    Encriptado[9][0] = "a9s_d8_asd_8-as-fdsf9dsf9ds59f59ds59fdsf59sd59f";
    Encriptado[10][0] = "dsfdsf6ds5_fds-f-ds5f9ds5f5ds6f6dsfdsfdsfjsdok7";
    Encriptado[11][0] = "f1g1dfg1d1fgrtyh1f1gh1fgytfy-fg1df1gdfg1df_dfgr";
    Encriptado[12][0] = "qwdfsdfsdffs5dfs99fvdf58df.df5g85sdf6-dsf5d4s5g";
    Encriptado[13][0] = "1f5g1vhbn5c1v5b1fg8h8f5g9hf9_gh9_dgfh56gfgh5f1s";
    Encriptado[14][0] = "dfgh4dfs4g5dfagdf-gfd4a8few5cv6c2x6v2xcv84cvx-d";
    Encriptado[15][0] = "dewydfg6bv6nb_9vnb_vn9jip_--iop59k5j9l9kjl959ln";
    Encriptado[16][0] = "zx48cxzv58cvcx15v9f-df_fd-f-d_f9-gfdg5fd5g5ffff";
    Encriptado[17][0] = "12xcvvc1vcv1c5xv15c--v-c-v.c8vc5v56df5v6cx51v5v";
    Encriptado[18][0] = "xc0x2v2sd1fd1sf1ds2f1d2s1f--s15f15dsf1s0dfdsfd0";
    Encriptado[19][0] = "rt4yhdf5g4df8g8ds4gfas49f9dasfa_df-a--s_dsadsdk";
    Encriptado[20][0] = "x1c1z51v5xc1v584gh8df8h4gf848h9gfhfg-gh-fg9h5gf";
    Encriptado[21][0] = "we2134dsfw456rgdsfdgfdsg15fdg22f1dgfd2-12f2g12d";
    Encriptado[22][0] = "dfgfdgfdgfdg21fg4fdg44df5g4df78g4df4g84dfg8_f4g";
    Encriptado[23][0] = "ewretryrty8rt5ghf51f51hgf-hgfh5gf_fgh4fg5hhgfgt";
    Encriptado[24][0] = "as8d14as58d1a5s1f15dsx15c14s8zadf5_9ad9asd8sd84";
    Encriptado[25][0] = "15xv1s8f48yh58rti81ty5uj1t81u5j1gh51n51gfbn515v";
    Encriptado[26][0] = "qw7e8qw8e7qwe48qw9rwq-e59wq58ed45as1d584as5d15s";
    Encriptado[27][0] = "9qeswr9e9t5f9g_df_gdf6g5df_g-d5vf95c9xv59xczz9z";
    Encriptado[28][0] = "sas1d55asd8asdasdgfa-s-dfasfsad--sad--s-adasdas";
    Encriptado[29][0] = "154as5d1a5sd1sssdssd5d1111115sa15598595548848_4";
    Encriptado[30][0] = "x1z5c158s1xc51z58d5sa5d151as5d1sa-d_as__sssss_-";
    Encriptado[31][0] = "xcz1c5s1d8f8dsf88ds8f8ds8d8s8d8sss8df4s8dfd58s_";
    Encriptado[32][0] = "5qw1515rt1y51hj5i15hjh8k9hjkl_hj_k__j___k_hjkj-";
    Encriptado[33][0] = "sx1f51sd5f5d1s15f15ds15-58ds88f9ds8f3d23-xcxz_c";
    Encriptado[34][0] = "bnmbncvbncvnbv6nb5v_n_b6v699b99v9b___bvnbv8nv--";
    Encriptado[35][0] = "1o5ip1io51p5oip2o6_p_oip26o2i6p2oiiiiii2p6___92";
    Encriptado[36][0] = "qw15e1q5w1e848r51454444d5sf4ds8f48sdfdsf_s_fd-s";
    Encriptado[37][0] = "xcv5xc1v1x2cv6xcv5cx9_xv---_xc5v59df48sdfs65df9";
    Encriptado[38][0] = "154x1<z51c5zx8cxz54cf8dsf4s4d8dsf48a5sd115ssv1c";
    Encriptado[39][0] = "qw5e48qw4e8qw18eewr95..r5ew49r5ew9rewr9w-e_w-e5";
    Encriptado[40][0] = "fjdfgbdhfhgfdgdsgfd-sf9ds-.f-ds-fd_sfcvcv_x_df5";
    Encriptado[41][0] = "v1b51cvfb1d8f58g48dfg8.fdg-fdg--df--fg89df5g6fd";
    Encriptado[42][0] = "1gf15sdfs56f59ds_f_ds__fd-s_f__ds9fd-sfdfd54sff";
    Encriptado[43][0] = "tqweuqwemqwhueqwoeqwuyu34.a9e9a---w5e9wa4de84wa";
    Encriptado[44][0] = "bhsabdhayhsgd_____-lpllpbvcbvc7b98v48b48444484-";
    Encriptado[45][0] = "bvhcxhbvhxcbvcxvc_xvcx_v6cx5vcx5v48v4cx5.-v.-__";
    Encriptado[46][0] = "162834672148uusbygfjsidfuh.-595_-9-9559--_udfnj";
    Encriptado[47][0] = "tsgd.48s58d.asd--asd5as98d59a__s548ad49as-5sad5";
    Encriptado[48][0] = "retre8t4r5et48ref2d1s5f46sdf9ds9_f-sd9f56d5s9f1";
    Encriptado[49][0] = "bhj.ds.f.d.sf48ds.f-.84ds8f9ds8-fdsfdsf9dsf-dss";
    Encriptado[50][0] = "bnvn54bv1n148bv48n48bvn9bv5nbv84nb_v9-n-vb--n-b";
    Encriptado[51][0] = "sa54d5as1f15scv55cv15hnj5h5o5ui5o55u4io488.i...";
    Encriptado[52][0] = "x11c14zx14c1554zx548c489589z595999__x__zc6ds9--";
    Encriptado[53][0] = "bxcvhbcvhxcvznjvjuzxjcmfjiidaufsd.asd9sa8-d_-as";
    Encriptado[54][0] = "das5d5asdasdasdasas15f1d5sf8d4s8f4ds8f48dsf.dsd";
    Encriptado[55][0] = "cx1xc1v11c1115vxv..c.v--cv99c58x8v-8xc-vvv59-55";
    Encriptado[56][0] = "cx151v5x15c1v515sd1515f5ds151f515sse5gfd5g5df59";
    Encriptado[57][0] = "yu48tyu8iyuiuy-i-uyi_u_y_i_yu9iuii_i9yu_iuyyyyy";
    Encriptado[58][0] = "sadhjasndfbhasdasfsa.-.d-a-9f9ad3_s6d5as2d26v26";
    Encriptado[59][0] = "uyi8uiyu5i26u-ty9ut_u2t5j415gf15j4fghfgh_-gfh56";
    Encriptado[60][0] = "bhdsnjgfmkdsnjhfhusdnjf......ds.f-----dsf---__d";
    Encriptado[61][0] = "vbvb11v15bcv51b51cv5bcv--cv..c.v..c.vb4vc54b415";
    Encriptado[62][0] = "9<-zc6xz<-6c99xz96c6_x_x_z_c__x__c6xzc66c66c6c9";
    Encriptado[63][0] = "--c-z-f-d--r-e-r--rt-t-tg-f9g9f-g9f999g99h9gh99";
    Encriptado[64][0] = "__67__g_f_tg__gfd__fd_re_r6d6f6dg99g99hh5h5hhhh";
    Encriptado[65][0] = "vc5v15xc5cvx5xxxcv6xc_vf96g6_fg6fd-g6fggg999---";
    Encriptado[66][0] = "dsgdhmfkidfgjudsgkidstgds25._--dfmkdsmkcgv_5v_d";
    Encriptado[67][0] = "dsfdshuhuokewpoibn_-.mmsvvvvvvvbfhgfjff--f5_55f";
    Encriptado[68][0] = "fgbgvslhjghepy1.8--gh146cf_6bhnjgas_-98g55h_-_h";
    Encriptado[69][0] = "ghrejutheirokhjuwer94759uidfg6-.-fg9-6s---d-.ds";
    Encriptado[70][0] = "asas-a_s6_as_a96s_a6s9dsd_s9df.f--98dfdjhyghdgd";
    Encriptado[71][0] = "fnbgdvdfhfujigjig786._-6___e--w9r-98wr5----ccsb";
    Encriptado[72][0] = "kaspqqpwieyur4.---_6995_y6r6egrhfdfsdhgadyau--5";
    Encriptado[73][0] = "68hjg8d1fs-5_-sd_f_ds6fsdfbvvnvkjjhk-j-hm6n_b_m";
    Encriptado[74][0] = "njcvdgjihug.--_6dfg5df59g4bcv564bnmj695u8565gg_";
    Encriptado[75][0] = "--cv.bcv9b5cvbudshufidsbhufdsf-9s9d_f9ds_965fds";
    Encriptado[76][0] = "knbxvcvd--._5-j5j599j59_h---bg6h5gfbhbdfs_6dfdd";
    Encriptado[77][0] = "vgywd1623huew--ds56d9_sd_6-dsfd_f9ds_gsfg6dfgd-";
    Encriptado[78][0] = "gfdghg9hgf5h95gf59hgf-h--fgh_fg-h_gf6bb_v6xcddv";
    Encriptado[79][0] = "bvmkvsnjjnvxnjzcvfhuddff.25vc54x9gv59dfg-dfg__-";
    Encriptado[80][0] = "rtikyortoiyoirtytr--t-ry.tr-y99_<kfgdjigidfdfgg";
    Encriptado[81][0] = "cnxhzvchdhsygfjsahdasd--sad--sad_as9d_sd9998<nj";
    Encriptado[82][0] = "8488gfh4f4gh8fg48h<949f8h59d99df--fdg_fd656v444";
    Encriptado[83][0] = "yewrfwuer6678..-58989959dfghusdgfhdshfgdiopl_--";
    Encriptado[84][0] = "dygsrfjiswrfdsf958ds45f14ds84f125dsf65sd4f1.-.-";
    Encriptado[85][0] = "yhuqhuwer<jigfyhdf.6dgf9d-__59f8-dg5--dfgdhfg45";
    Encriptado[86][0] = "ygasudiysfl348534583465-.-6_9_-----_95f9g5fd5_9";
    Encriptado[87][0] = "ds1f8s15f1884-599----dsf9df95sdffffff555599ssdf";
    Encriptado[88][0] = "m8b8n8m888bn888m8nbmnb--m848n8b4m__cgdf54gdf8dd";
    Encriptado[89][0] = "rty1r1ty1tr1y1tr5y555555----rtyt-r-y---___rtree";
    Encriptado[90][0] = "x511z5xc1x15--__xcvdfvbgnghkhgjh-j48gh2j51jhg56";
    Encriptado[91][0] = "b1n51m-nb5m59b5nm___bnmnbm-6b26m6ghj62hgj559g66";
    Encriptado[92][0] = "v8vvv8451b518gf5h59fg89f5g9ht99y59ty95h6g6626gf";
    Encriptado[93][0] = "8fg4h8fg5r515r1t8--re4t8-___rete8956264--5re54t";
}

void L_ENCRIP(string CADENA_ENTRADA,ofstream *SALIDA_ENCRIPTADA){

    for(int i = 0 ;CADENA_ENTRADA[i];i++){ ///AVANZA TODA LA CADENA
          switch (CADENA_ENTRADA[i]){
                case ' ': *SALIDA_ENCRIPTADA<<Encriptado[0][0];break;
                case '!': *SALIDA_ENCRIPTADA<<Encriptado[1][0];break;
                case '"': *SALIDA_ENCRIPTADA<<Encriptado[2][0];break;
                case '#': *SALIDA_ENCRIPTADA<<Encriptado[3][0];break;
                case '$': *SALIDA_ENCRIPTADA<<Encriptado[4][0];break;
                case '%': *SALIDA_ENCRIPTADA<<Encriptado[5][0];break;
                case '&': *SALIDA_ENCRIPTADA<<Encriptado[6][0];break;
                case 39 : *SALIDA_ENCRIPTADA<<Encriptado[7][0];break;
                case '(': *SALIDA_ENCRIPTADA<<Encriptado[8][0];break;
                case ')': *SALIDA_ENCRIPTADA<<Encriptado[9][0];break;
                case '*': *SALIDA_ENCRIPTADA<<Encriptado[10][0];break;
                case '+': *SALIDA_ENCRIPTADA<<Encriptado[11][0];break;
                case ',': *SALIDA_ENCRIPTADA<<Encriptado[12][0];break;
                case '-': *SALIDA_ENCRIPTADA<<Encriptado[13][0];break;
                case '.': *SALIDA_ENCRIPTADA<<Encriptado[14][0];break;
                case '/': *SALIDA_ENCRIPTADA<<Encriptado[15][0];break;
                case '0': *SALIDA_ENCRIPTADA<<Encriptado[16][0];break;
                case '1': *SALIDA_ENCRIPTADA<<Encriptado[17][0];break;
                case '2': *SALIDA_ENCRIPTADA<<Encriptado[18][0];break;
                case '3': *SALIDA_ENCRIPTADA<<Encriptado[19][0];break;
                case '4': *SALIDA_ENCRIPTADA<<Encriptado[20][0];break;
                case '5': *SALIDA_ENCRIPTADA<<Encriptado[21][0];break;
                case '6': *SALIDA_ENCRIPTADA<<Encriptado[22][0];break;
                case '7': *SALIDA_ENCRIPTADA<<Encriptado[23][0];break;
                case '8': *SALIDA_ENCRIPTADA<<Encriptado[24][0];break;
                case '9': *SALIDA_ENCRIPTADA<<Encriptado[25][0];break;
                case ':': *SALIDA_ENCRIPTADA<<Encriptado[26][0];break;
                case ';': *SALIDA_ENCRIPTADA<<Encriptado[27][0];break;
                case '<': *SALIDA_ENCRIPTADA<<Encriptado[28][0];break;
                case '=': *SALIDA_ENCRIPTADA<<Encriptado[29][0];break;
                case '>': *SALIDA_ENCRIPTADA<<Encriptado[30][0];break;
                case '?': *SALIDA_ENCRIPTADA<<Encriptado[31][0];break;
                case '@': *SALIDA_ENCRIPTADA<<Encriptado[32][0];break;
                case 'A': *SALIDA_ENCRIPTADA<<Encriptado[33][0];break;
                case 'B': *SALIDA_ENCRIPTADA<<Encriptado[34][0];break;
                case 'C': *SALIDA_ENCRIPTADA<<Encriptado[35][0];break;
                case 'D': *SALIDA_ENCRIPTADA<<Encriptado[36][0];break;
                case 'E': *SALIDA_ENCRIPTADA<<Encriptado[37][0];break;
                case 'F': *SALIDA_ENCRIPTADA<<Encriptado[38][0];break;
                case 'G': *SALIDA_ENCRIPTADA<<Encriptado[39][0];break;
                case 'H': *SALIDA_ENCRIPTADA<<Encriptado[40][0];break;
                case 'I': *SALIDA_ENCRIPTADA<<Encriptado[41][0];break;
                case 'J': *SALIDA_ENCRIPTADA<<Encriptado[42][0];break;
                case 'K': *SALIDA_ENCRIPTADA<<Encriptado[43][0];break;
                case 'L': *SALIDA_ENCRIPTADA<<Encriptado[44][0];break;
                case 'M': *SALIDA_ENCRIPTADA<<Encriptado[45][0];break;
                case 'N': *SALIDA_ENCRIPTADA<<Encriptado[46][0];break;
                case 'O': *SALIDA_ENCRIPTADA<<Encriptado[47][0];break;
                case 'P': *SALIDA_ENCRIPTADA<<Encriptado[48][0];break;
                case 'Q': *SALIDA_ENCRIPTADA<<Encriptado[49][0];break;
                case 'R': *SALIDA_ENCRIPTADA<<Encriptado[50][0];break;
                case 'S': *SALIDA_ENCRIPTADA<<Encriptado[51][0];break;
                case 'T': *SALIDA_ENCRIPTADA<<Encriptado[52][0];break;
                case 'U': *SALIDA_ENCRIPTADA<<Encriptado[53][0];break;
                case 'V': *SALIDA_ENCRIPTADA<<Encriptado[54][0];break;
                case 'W': *SALIDA_ENCRIPTADA<<Encriptado[55][0];break;
                case 'X': *SALIDA_ENCRIPTADA<<Encriptado[56][0];break;
                case 'Y': *SALIDA_ENCRIPTADA<<Encriptado[57][0];break;
                case 'Z': *SALIDA_ENCRIPTADA<<Encriptado[58][0];break;
                case '[': *SALIDA_ENCRIPTADA<<Encriptado[59][0];break;
                case 92 : *SALIDA_ENCRIPTADA<<Encriptado[60][0];break;
                case ']': *SALIDA_ENCRIPTADA<<Encriptado[61][0];break;
                case '^': *SALIDA_ENCRIPTADA<<Encriptado[62][0];break;
                case '_': *SALIDA_ENCRIPTADA<<Encriptado[63][0];break;
                case '`': *SALIDA_ENCRIPTADA<<Encriptado[64][0];break;
                case 'a': *SALIDA_ENCRIPTADA<<Encriptado[65][0];break;
                case 'b': *SALIDA_ENCRIPTADA<<Encriptado[66][0];break;
                case 'c': *SALIDA_ENCRIPTADA<<Encriptado[67][0];break;
                case 'd': *SALIDA_ENCRIPTADA<<Encriptado[68][0];break;
                case 'e': *SALIDA_ENCRIPTADA<<Encriptado[69][0];break;
                case 'f': *SALIDA_ENCRIPTADA<<Encriptado[70][0];break;
                case 'g': *SALIDA_ENCRIPTADA<<Encriptado[71][0];break;
                case 'h': *SALIDA_ENCRIPTADA<<Encriptado[72][0];break;
                case 'i': *SALIDA_ENCRIPTADA<<Encriptado[73][0];break;
                case 'j': *SALIDA_ENCRIPTADA<<Encriptado[74][0];break;
                case 'k': *SALIDA_ENCRIPTADA<<Encriptado[75][0];break;
                case 'l': *SALIDA_ENCRIPTADA<<Encriptado[76][0];break;
                case 'm': *SALIDA_ENCRIPTADA<<Encriptado[77][0];break;
                case 'n': *SALIDA_ENCRIPTADA<<Encriptado[78][0];break;
                case 'o': *SALIDA_ENCRIPTADA<<Encriptado[79][0];break;
                case 'p': *SALIDA_ENCRIPTADA<<Encriptado[80][0];break;
                case 'q': *SALIDA_ENCRIPTADA<<Encriptado[81][0];break;
                case 'r': *SALIDA_ENCRIPTADA<<Encriptado[82][0];break;
                case 's': *SALIDA_ENCRIPTADA<<Encriptado[83][0];break;
                case 't': *SALIDA_ENCRIPTADA<<Encriptado[84][0];break;
                case 'u': *SALIDA_ENCRIPTADA<<Encriptado[85][0];break;
                case 'v': *SALIDA_ENCRIPTADA<<Encriptado[86][0];break;
                case 'w': *SALIDA_ENCRIPTADA<<Encriptado[87][0];break;
                case 'x': *SALIDA_ENCRIPTADA<<Encriptado[88][0];break;
                case 'y': *SALIDA_ENCRIPTADA<<Encriptado[89][0];break;
                case 'z': *SALIDA_ENCRIPTADA<<Encriptado[90][0];break;
                case '{': *SALIDA_ENCRIPTADA<<Encriptado[91][0];break;
                case '|': *SALIDA_ENCRIPTADA<<Encriptado[92][0];break;
                case '}': *SALIDA_ENCRIPTADA<<Encriptado[93][0];break;
          }
    }
}


//void ENCRIPTAR()
//{
//
//
//    ofstream SALIDA_ENCRIPTADA;
//    SALIDA_ENCRIPTADA.open("MYCOUTS_P.cpeaxel");
//
//    L_ENCRIP(Comando[0],&SALIDA_ENCRIPTADA);
//
////    char COM = 34;
////    for(int i=0;i<=93;i++){
////        cout<<"contenido = contenido.replace(/"<<Encriptado[i][0]<<"/gi, "<<COM<<Encriptado[i][1]<<COM<<")"<<endl;
////    }
//}

string MAYUSCULAS(string CADENA){
     for(int i = 0;CADENA[i];i++){
          if((int)CADENA[i]>96&&(int)CADENA[i]<123){
            CADENA[i] = CADENA[i]-32;
          }
     }
     return CADENA;
}

string CONVERSOR_INT_A_STRING(int M){
    char *C;int N=M;
    int i = 0;for(;N>9;N/=10,i++);C = new char[i+1];C[i]='\0';
    while(M>9){
         C[i]=(char)(M%10+48);
         M/=10;i--;
    }
    C[i]=(char)(M+48);
    return C;
}

bool V_CHAR(string CAD){
     for(int i = 0;CAD[i]; i++){
        if(CAD[i]>=32&&CAD[i]<=126){

        }else{
            return 0;
        }
     }
     return 1;
}


////////////////////////////////////////////////////////

class NODO_DAT_CUENTA
{
    public:
    int ORDEN_CUENTA;
    string USER,PASSWORD,CORREO,CORREO_USER_VERIFICACION,CORREO_PASSWORD_VERIFICACION
           ,DOC_IDENTIDAD,TELEFONO1,TELEFONO2,PREGUNTA_VALIDACION,NUM_TARGETA,NUM_CUENTA
           ,PASSWORD_VIRTUAL,VCC,FECH_VENCIMIENTO;
    NODO_DAT_CUENTA *SIGUIENTE;
    NODO_DAT_CUENTA(string USE,string PASSWOR,string D_CORREO,string CORREO_USER_VERIFIC,string CORREO_PASSWOR_VERIFIC,string DOC_IDEN,string TLFONO1,string TLFONO2,string PREGUN_VALID,string NUM_TARG,string NUM_CUEN,string PASSWOR_VIR,string N_VCC,string FECH_VEN,int N_COUNT,NODO_DAT_CUENTA *SIG=NULL){
         ORDEN_CUENTA = N_COUNT;
         USER = USE;
         PASSWORD = PASSWOR;
         CORREO = D_CORREO;
         CORREO_USER_VERIFICACION = CORREO_USER_VERIFIC;
         CORREO_PASSWORD_VERIFICACION = CORREO_PASSWOR_VERIFIC;
         DOC_IDENTIDAD = DOC_IDEN;
         TELEFONO1 = TLFONO1;
         TELEFONO2 = TLFONO2;
         PREGUNTA_VALIDACION = PREGUN_VALID;
         NUM_TARGETA = NUM_TARG;
         NUM_CUENTA = NUM_CUEN;
         PASSWORD_VIRTUAL = PASSWOR_VIR;
         VCC = N_VCC;
         FECH_VENCIMIENTO = FECH_VEN;

         SIGUIENTE=SIG;
    }
};

class LISTA_CUENTAS{
    public:
    NODO_DAT_CUENTA *raiz;
    LISTA_CUENTAS(){
        raiz=NULL;
    }
    void INSERTAR(string USER, string PASSWORD,string D_CORREO,string CORREO_USER_VERIFIC,string CORREO_PASSWOR_VERIFIC,string DOC_IDEN,string TLFONO1,string TLFONO2,string PREGUN_VALID,string NUM_TARG,string NUM_CUEN,string PASSWOR_VIR,string N_VCC,string FECH_VEN){
         INS(USER,PASSWORD,D_CORREO,CORREO_USER_VERIFIC,CORREO_PASSWOR_VERIFIC,DOC_IDEN,TLFONO1,TLFONO2,PREGUN_VALID,NUM_TARG,NUM_CUEN,PASSWOR_VIR,N_VCC,FECH_VEN,CANTIDAD_DE_CUENTAS(raiz),raiz);
    }
    void INS(string USER,string PASSWORD,string D_CORREO,string CORREO_USER_VERIFIC,string CORREO_PASSWOR_VERIFIC,string DOC_IDEN,string TLFONO1,string TLFONO2,string PREGUN_VALID,string NUM_TARG,string NUM_CUEN,string PASSWOR_VIR,string N_VCC,string FECH_VEN,int N_CUENTA,NODO_DAT_CUENTA *&R){
         if(R==NULL)
            R=new NODO_DAT_CUENTA(USER,PASSWORD,D_CORREO,CORREO_USER_VERIFIC,CORREO_PASSWOR_VERIFIC,DOC_IDEN,TLFONO1,TLFONO2,PREGUN_VALID,NUM_TARG,NUM_CUEN,PASSWOR_VIR,N_VCC,FECH_VEN,N_CUENTA);
         else
            INS(USER,PASSWORD,D_CORREO,CORREO_USER_VERIFIC,CORREO_PASSWOR_VERIFIC,DOC_IDEN,TLFONO1,TLFONO2,PREGUN_VALID,NUM_TARG,NUM_CUEN,PASSWOR_VIR,N_VCC,FECH_VEN,N_CUENTA,R->SIGUIENTE);
    }
    int CANTIDAD_DE_CUENTAS(NODO_DAT_CUENTA *R){
        int i = 1;for(; R != NULL ;i++){
                R = R->SIGUIENTE;
        }
        return i;
    }
    void REASIGNAR_CUENTAS(NODO_DAT_CUENTA *R){
        int i = 1;for(; R != NULL ;i++){
                R->ORDEN_CUENTA = i;
                R = R->SIGUIENTE;
        }
    }
    bool BUSCARYMODIFICAR_VALOR(bool V,int N_CUENTA,int DIRECCION,string VALOR_NEW){
         return BUSC_V(raiz,V,N_CUENTA,DIRECCION,VALOR_NEW);
    }
    bool BUSC_V(NODO_DAT_CUENTA *R,bool V,int N_CUENTA,int DIRECCION,string VALOR_NEW){

        switch(DIRECCION){
                case 0:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_USER(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 1:            ///password
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_PASSWORD(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 2:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_CORREO(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 3:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_CORREO_USER_VERIFICACION(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 4:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_CORREO_PASSWORD_VERIFICACION(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 5:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_DOC_IDENTIDAD(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 6:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_TELEFONO1(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 7:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_TELEFONO2(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 8:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_PREGUNTA_VALIDACION(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 9:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_NUM_TARGETA(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 10:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_NUM_CUENTA(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 11:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_PASSWORD_VIRTUAL(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 12:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_VCC(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 13:            ///user
                    for(;R != NULL;){
                         if(N_CUENTA == R->ORDEN_CUENTA){
                            if(V==1){///mostrar
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_FECH_VENCIMIENTO(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;

        }
        return 0;
    }
    void MODIFICAR_USER(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->USER = VALOR_NEW;
    }

    void MODIFICAR_PASSWORD(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->PASSWORD = VALOR_NEW;
    }

    void MODIFICAR_CORREO(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->CORREO = VALOR_NEW;
    }

    void MODIFICAR_CORREO_USER_VERIFICACION(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->CORREO_USER_VERIFICACION = VALOR_NEW;
    }

    void MODIFICAR_CORREO_PASSWORD_VERIFICACION(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->CORREO_PASSWORD_VERIFICACION = VALOR_NEW;
    }

    void MODIFICAR_DOC_IDENTIDAD(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->DOC_IDENTIDAD = VALOR_NEW;
    }

    void MODIFICAR_TELEFONO1(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->TELEFONO1 = VALOR_NEW;
    }

    void MODIFICAR_TELEFONO2(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->TELEFONO2 = VALOR_NEW;
    }

    void MODIFICAR_PREGUNTA_VALIDACION(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->PREGUNTA_VALIDACION = VALOR_NEW;
    }

    void MODIFICAR_NUM_TARGETA(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->NUM_TARGETA = VALOR_NEW;
    }

    void MODIFICAR_NUM_CUENTA(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->NUM_CUENTA = VALOR_NEW;
    }

    void MODIFICAR_PASSWORD_VIRTUAL(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->PASSWORD_VIRTUAL = VALOR_NEW;
    }

    void MODIFICAR_VCC(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->VCC = VALOR_NEW;
    }

    void MODIFICAR_FECH_VENCIMIENTO(string VALOR_NEW,NODO_DAT_CUENTA *&R){
        R->FECH_VENCIMIENTO = VALOR_NEW;
    }

    bool ELIMINAR_CUENTA(int VALOR){
         bool Rt;
         Rt = ELIM(VALOR,raiz);
         REASIGNAR_CUENTAS(raiz);
         return Rt;
    }
    bool ELIM(int VALOR,NODO_DAT_CUENTA *&R){
         if(R!=NULL){
              NODO_DAT_CUENTA *AUX_BORRAR = R;
              NODO_DAT_CUENTA *ANTERIOR = NULL;
              while(AUX_BORRAR!=NULL&&AUX_BORRAR->ORDEN_CUENTA!=VALOR){
                   ANTERIOR = AUX_BORRAR;
                   AUX_BORRAR = AUX_BORRAR->SIGUIENTE;
              }
              if(AUX_BORRAR == NULL){
                   return 0;
              }else if(ANTERIOR == NULL){
                   R = R->SIGUIENTE;
                   delete AUX_BORRAR;
              }else{
                   ANTERIOR->SIGUIENTE = AUX_BORRAR->SIGUIENTE;
                   delete AUX_BORRAR;
              }
         }else{
              return 0;
         }
         return 1;
    }
    void MOSTRAR_CMD(ofstream *SALIDA_ENCRIPTADA,bool V){
         MOS(raiz,SALIDA_ENCRIPTADA,V);

    }
    void MOS(NODO_DAT_CUENTA *R,ofstream *SALIDA_ENCRIPTADA,bool V){

         while(R!=NULL){
                if(V){

                    cout<<"     - CUENTA "<<R->ORDEN_CUENTA<<":\n\n";
                    if(R->USER[0]!='\0'){

                        cout<<"          Usuario:"<<R->USER<<"\n";
                    }
                    if(R->PASSWORD[0]!='\0'){

                        cout<<"          password:"<<R->PASSWORD<<"\n";;
                    }
                    if(R->CORREO[0]!='\0'){

                        cout<<"          Correo:"<<R->CORREO<<"\n";;
                    }
                    if(R->CORREO_USER_VERIFICACION[0]!='\0'){

                        cout<<"          Correo de verificacion usuario:"<<R->CORREO_USER_VERIFICACION<<"\n";;
                    }
                    if(R->CORREO_PASSWORD_VERIFICACION[0]!='\0'){
                        cout<<"          Correo de verificacion password:"<<R->CORREO_PASSWORD_VERIFICACION<<"\n";;
                    }
                    if(R->DOC_IDENTIDAD[0]!='\0'){
                        cout<<"          DNI:"<<R->DOC_IDENTIDAD<<"\n";;
                    }
                    if(R->TELEFONO1[0]!='\0'){
                        cout<<"          Telefono 1:"<<R->TELEFONO1<<"\n";;
                    }
                    if(R->TELEFONO2[0]!='\0'){
                        cout<<"          Telefono 2:"<<R->TELEFONO2<<"\n";;
                    }
                    if(R->PREGUNTA_VALIDACION[0]!='\0'){
                        cout<<"          Pregunta de validacion:"<<R->PREGUNTA_VALIDACION<<"\n";;
                    }
                    if(R->NUM_TARGETA[0]!='\0'){
                        cout<<"          Numero Tarjeta:"<<R->NUM_TARGETA<<"\n";;
                    }
                    if(R->NUM_CUENTA[0]!='\0'){
                        cout<<"          Numero de Cuenta:"<<R->NUM_CUENTA<<"\n";;
                    }
                    if(R->PASSWORD_VIRTUAL[0]!='\0'){
                        cout<<"          Password Virtual:"<<R->PASSWORD_VIRTUAL<<"\n";;
                    }
                    if(R->VCC[0]!='\0'){
                        cout<<"          Vcc:"<<R->VCC<<"\n";;
                    }
                    if(R->FECH_VENCIMIENTO[0]!='\0'){
                        cout<<"          Fecha de Vencimiento:"<<R->FECH_VENCIMIENTO<<"\n";
                    }cout<<"\n";
                }else{
                    cout<<"@@@"<<R->ORDEN_CUENTA<<"<>"
                        <<R->USER<<"<>"
                        <<R->PASSWORD<<"<>"
                        <<R->CORREO<<"<>"
                        <<R->CORREO_USER_VERIFICACION<<"<>"
                        <<R->CORREO_PASSWORD_VERIFICACION<<"<>"
                        <<R->DOC_IDENTIDAD<<"<>"
                        <<R->TELEFONO1<<"<>"
                        <<R->TELEFONO2<<"<>"
                        <<R->PREGUNTA_VALIDACION<<"<>"
                        <<R->NUM_TARGETA<<"<>"
                        <<R->NUM_CUENTA <<"<>"
                        <<R->PASSWORD_VIRTUAL<<"<>"
                        <<R->VCC<<"<>"
                        <<R->FECH_VENCIMIENTO<<"&&&\n";
                }

            L_ENCRIP("@@@",SALIDA_ENCRIPTADA);
            L_ENCRIP(CONVERSOR_INT_A_STRING(R->ORDEN_CUENTA),SALIDA_ENCRIPTADA);
            L_ENCRIP("<c>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->USER,SALIDA_ENCRIPTADA);
            L_ENCRIP("<d>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->PASSWORD,SALIDA_ENCRIPTADA);
            L_ENCRIP("<e>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->CORREO,SALIDA_ENCRIPTADA);
            L_ENCRIP("<f>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->CORREO_USER_VERIFICACION,SALIDA_ENCRIPTADA);
            L_ENCRIP("<g>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->CORREO_PASSWORD_VERIFICACION,SALIDA_ENCRIPTADA);
            L_ENCRIP("<h>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->DOC_IDENTIDAD,SALIDA_ENCRIPTADA);
            L_ENCRIP("<i>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->TELEFONO1,SALIDA_ENCRIPTADA);
            L_ENCRIP("<j>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->TELEFONO2,SALIDA_ENCRIPTADA);
            L_ENCRIP("<k>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->PREGUNTA_VALIDACION,SALIDA_ENCRIPTADA);
            L_ENCRIP("<l>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->NUM_TARGETA,SALIDA_ENCRIPTADA);
            L_ENCRIP("<m>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->NUM_CUENTA,SALIDA_ENCRIPTADA);
            L_ENCRIP("<n>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->PASSWORD_VIRTUAL,SALIDA_ENCRIPTADA);
            L_ENCRIP("<o>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->VCC,SALIDA_ENCRIPTADA);
            L_ENCRIP("<p>",SALIDA_ENCRIPTADA);
            L_ENCRIP(R->FECH_VENCIMIENTO,SALIDA_ENCRIPTADA);
            L_ENCRIP("&&&\n",SALIDA_ENCRIPTADA);

            R = R->SIGUIENTE;
         }
    }
};

////////////////////////////////////////////////////////

class NODO_APP
{
    public:

    string NOMBRE_APP,LINK_APP,DESCRIPCION_APP;

    LISTA_CUENTAS S;

    NODO_APP *SIGUIENTE;
    NODO_APP(string NM_APP,string LNK_APP,string DES_APP,NODO_APP *SIG=NULL){

         NOMBRE_APP = NM_APP;
         LINK_APP = LNK_APP;
         DESCRIPCION_APP = DES_APP;

         SIGUIENTE=SIG;
    }
};

class LISTA_APPS{
    public:
    NODO_APP *raiz;
    LISTA_APPS(){
        raiz=NULL;
    }
    bool INSERTAR(string NOMBRE_APP, string LINK_APP,string DESCR_APP){
         return INS(MAYUSCULAS(NOMBRE_APP),LINK_APP,DESCR_APP,raiz);
    }
    bool INS(string NOMBRE_APP,string LINK_APP,string DESCR_APP,NODO_APP *&R){

         if(R==NULL){

            R=new NODO_APP(NOMBRE_APP,LINK_APP,DESCR_APP);
            return 1;

         }else if(R->NOMBRE_APP != NOMBRE_APP){

            return INS(NOMBRE_APP,LINK_APP,DESCR_APP,R->SIGUIENTE);

         }else{

            return 0;
         }
    }

    bool BUSCARYMODIFICAR_VALOR(bool V = 0,string NOM_APP = "",int DIRECCION = 0,string VALOR_NEW = "",string D1 = "",string D2 = "",string D3 = "",string D4 = "",string D5 = "",string D6 = "",string D7 = "",string D8 = "",string D9 = "",string D10 = "",string D11 = "",string D12 = "",string D13 = "",string D14 =""){
         return BUSC_V( raiz, V, MAYUSCULAS(NOM_APP), DIRECCION, VALOR_NEW, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14);
    }
    bool BUSC_V(NODO_APP *R,bool V,string NOM_APP,int DIRECCION,string VALOR_NEW,string D1,string D2,string D3,string D4,string D5,string D6,string D7,string D8,string D9,string D10,string D11,string D12,string D13,string D14){

        switch(DIRECCION){
                case 0:            ///NOMBRE APP
                    for(;R != NULL;){
                         if(NOM_APP == R->NOMBRE_APP){
                            if(V==1){                       ///MOSTRAR

                                R->S.INSERTAR( D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14);
                                return 1;

                            }else{
                                MODIFICAR_NOMBRE_APP(MAYUSCULAS(VALOR_NEW),R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 1:            ///LINK
                    for(;R != NULL;){
                         if(NOM_APP == R->NOMBRE_APP){
                            if(V==1){
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_LINK_APP(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;
                case 2:            ///DESCRIPCION
                    for(;R != NULL;){
                         if(NOM_APP == R->NOMBRE_APP){
                            if(V==1){
                                cout<<"EXISTE!";
                            }else{
                                MODIFICAR_DESCRIPCION_APP(VALOR_NEW,R);
                                return 1;
                            }
                         }
                         R=R->SIGUIENTE;
                    }
                    break;

        }
        return 0;
    }               //bool V,int N_CUENTA,int DIRECCION,string VALOR_NEW
    bool MODIFICAR_DATOS_CUENTA_SEC(string NOM_APP = "",bool V = 0,int D1 = 0,int D2 = 0,string D3 = ""){
         return MODIF_SEC( raiz, MAYUSCULAS(NOM_APP), V, D1, D2, D3);
    }
    bool MODIF_SEC(NODO_APP *R,string NOM_APP,bool V,int D1,int D2,string D3){

        for(;R != NULL;){
             if(NOM_APP == R->NOMBRE_APP){
                if(V == 0){

                    return R->S.BUSCARYMODIFICAR_VALOR(0,D1,D2,D3);

                }else{

                    return R->S.ELIMINAR_CUENTA(D1);

                }
             }
             R=R->SIGUIENTE;
        }
        return 0;
    }
    void MODIFICAR_NOMBRE_APP(string VALOR_NEW,NODO_APP *&R){
        R->NOMBRE_APP = VALOR_NEW;
    }

    void MODIFICAR_LINK_APP(string VALOR_NEW,NODO_APP *&R){
        R->LINK_APP = VALOR_NEW;
    }

    void MODIFICAR_DESCRIPCION_APP(string VALOR_NEW,NODO_APP *&R){
        R->DESCRIPCION_APP = VALOR_NEW;
    }

    bool ELIMINAR_APP(string VALOR){
         return ELIM(VALOR,raiz);
    }
    bool ELIM(string VALOR,NODO_APP *&R){
         if(R!=NULL){
              NODO_APP *AUX_BORRAR = R;
              NODO_APP *ANTERIOR = NULL;
              while(AUX_BORRAR!=NULL&&AUX_BORRAR->NOMBRE_APP!=VALOR){
                   ANTERIOR = AUX_BORRAR;
                   AUX_BORRAR = AUX_BORRAR->SIGUIENTE;
              }
              if(AUX_BORRAR == NULL){
                   return 0;
              }else if(ANTERIOR == NULL){
                   R = R->SIGUIENTE;
                   delete AUX_BORRAR;
              }else{
                   ANTERIOR->SIGUIENTE = AUX_BORRAR->SIGUIENTE;
                   delete AUX_BORRAR;
              }
         }else{
            return 0;
         }
         return 1;
    }
    void MOSTRAR_CMD(bool V){
         system("cls");
         MOS(raiz,V);
    }
    void MOS(NODO_APP *R,bool V){

         ofstream SALIDA_ENCRIPTADA;
                  SALIDA_ENCRIPTADA.open("MYCOUTS.cpeaxel");


         while(R!=NULL){
            if(V){
                cout<<" NOMBRE DE APLICACION:  "<<R->NOMBRE_APP<<"\n    Descripcion      :  "
                    <<R->LINK_APP<<"\n    Direccion        :  "
                    <<R->DESCRIPCION_APP<<"\n\n";

            }else{
                cout<<":::"<<R->NOMBRE_APP<<"<>"<<R->LINK_APP<<"<>"<<R->DESCRIPCION_APP<<"%%%\n";

            }
            L_ENCRIP(":::",&SALIDA_ENCRIPTADA);
            L_ENCRIP(R->NOMBRE_APP,&SALIDA_ENCRIPTADA);
            L_ENCRIP("<a>",&SALIDA_ENCRIPTADA);
            L_ENCRIP(R->LINK_APP,&SALIDA_ENCRIPTADA);
            L_ENCRIP("<b>",&SALIDA_ENCRIPTADA);
            L_ENCRIP(R->DESCRIPCION_APP,&SALIDA_ENCRIPTADA);
            L_ENCRIP("%%%\n",&SALIDA_ENCRIPTADA);

            R->S.MOSTRAR_CMD(&SALIDA_ENCRIPTADA,V);

            R=R->SIGUIENTE;
         }

         SALIDA_ENCRIPTADA.close();
    }
}A;

void INSERTA_AP(){

    A.INSERTAR(INS_AP[0],INS_AP[1],INS_AP[2]);
}
void INSERTA_CT(){

    A.BUSCARYMODIFICAR_VALOR(1,INS_AP[0],0,"",INS_CT[1],INS_CT[2],INS_CT[3],INS_CT[4],INS_CT[5],INS_CT[6],INS_CT[7],INS_CT[8],INS_CT[9],INS_CT[10],INS_CT[11],INS_CT[12],INS_CT[13],INS_CT[14]);
}

char AUX_CAD[65];void CONCATENAR(string CAD,bool B){
    int i = 0;
    if(B){
        for(;ENTRADA_C[i];i++);
        ENTRADA_C[i]=CAD[0];
        ENTRADA_C[i+1]='\0';
    }else{
        for(;AUX_CAD[i];i++);
        AUX_CAD[i]=CAD[0];
        AUX_CAD[i+1]='\0';
    }
}

void DES_ENCRIPTADO(string CAD){
    for(int i=0;i<94;i++){
        if(CAD==Encriptado[i][0]){
            CONCATENAR(Encriptado[i][1],1);
        }
    }
}

void SEPARADOR_DE_CADENA(string a,int Tamanio){
    for(int i = 0,j=Tamanio;;i++){
        if(i == j){j+=Tamanio;
            DES_ENCRIPTADO(AUX_CAD);
            AUX_CAD[0]='\0';
        }
        CONCATENAR(&a[i],0);
        if(a[i]=='\0'){break;}
    }
}


bool CREAR_APP(string LINEA, int *i){
    int POSITION=0;
    for(int j = *i; LINEA[j] != '\0' ; j++){

        if(LINEA[j]=='<'&&LINEA[j+2]=='>'){*i=j=j+3;

            INS_AP[POSITION] = AUX_CAD;
            AUX_CAD[0]='\0';POSITION++;

            for(; LINEA[j] != '\0';j++){

                if(LINEA[j]=='<'&&LINEA[j+2]=='>'){*i=j=j-1;break;}
                if(LINEA[j]=='%'&&LINEA[j+1]=='%'&&LINEA[j+2]=='%'){*i=j=j+3;
                    INS_AP[POSITION] = AUX_CAD;
                    AUX_CAD[0]='\0';
                    return 1;
                }

                CONCATENAR(&LINEA[j],0);

            }
        }else{

            CONCATENAR(&LINEA[j],0);

        }
    }
    return 1;
}

bool CREAR_CUENTA(string LINEA, int *i){
    int POSITION=0;
    for(int j = *i; LINEA[j] != '\0' ; j++){

        if(LINEA[j]=='<'&&LINEA[j+2]=='>'){*i=j=j+3;

            INS_CT[POSITION] = AUX_CAD;
            AUX_CAD[0]='\0';POSITION++;

            for(; LINEA[j] != '\0' ; j++){

                if(LINEA[j]=='<'&&LINEA[j+2]=='>'){*i=j=j-1;break;}
                if(LINEA[j]=='&'&&LINEA[j+1]=='&'&&LINEA[j+2]=='&'){*i=j=j+2;
                    INS_CT[POSITION] = AUX_CAD;
                    AUX_CAD[0]='\0';
                    return 1;
                }

                CONCATENAR(&LINEA[j],0);

            }
        }else{

            CONCATENAR(&LINEA[j],0);

        }

    }
    return 1;
}

void INTERPRETE(string LINEA){

    for(int i = 0 ;LINEA[i];i++){ ///AVANZA TODA LA CADENA

        if(LINEA[i]==':'&&LINEA[i+1]==':'&&LINEA[i+2]==':'){i+=3;

            CREAR_APP(LINEA,&i);
            INSERTA_AP();

        }

        if(LINEA[i]=='@'&&LINEA[i+1]=='@'&&LINEA[i+2]=='@'){i+=3;

            CREAR_CUENTA(LINEA,&i);
            INSERTA_CT();

        }
    }
}

void LEER_DATOS(){
//    string LINEA;
    string LII;

//    ifstream MI_ARCHIVO ("RESULTADO.txt");
    ifstream MY_ENCRIPTT ("MYCOUTS.cpeaxel");
//    if (MI_ARCHIVO.is_open())
//    {
//        while ( getline (MI_ARCHIVO,LINEA) )
//        {
//          INTERPRETE(LINEA);
//        }
//        MI_ARCHIVO.close();
//    }
    if (MY_ENCRIPTT.is_open())
    {
        while ( getline (MY_ENCRIPTT,LII) )
        {
          //cout<<LII;
          SEPARADOR_DE_CADENA(LII,47);
        }
        MY_ENCRIPTT.close();
    }
    //cout<<ENTRADA_C;
    INTERPRETE(ENTRADA_C);
}


void VISUAL_DESING(HDC hdc){

        brushBlack=CreateSolidBrush(RGB(0, 0, 0));
        brushWhite=CreateSolidBrush(RGB(255, 255, 255));
        greenPen=CreatePen(PS_SOLID, 2, RGB(51, 204, 255));

        actual = SetTextColor(hdc, RGB(0,220,255));

        SelectObject(hdc,brushBlack);
        Rectangle(hdc,-5,-5,1310,610);
        DeleteObject(brushBlack);

        SelectObject(hdc,greenPen);
        SelectObject(hdc,brushWhite);

        Rectangle(hdc,5,5,445,50);
        Rectangle(hdc,5,60,445,95);
        Rectangle(hdc,5,105,445,280);
        Rectangle(hdc,5,290,445,460);
        Rectangle(hdc,5,470,445,590);

        Rectangle(hdc,464,5,906,50);
        Rectangle(hdc,464,60,906,590);

        Rectangle(hdc,927,5,1300,92);
        Rectangle(hdc,927,102,1300,340);
        Rectangle(hdc,927,350,1300,590);



        TextOut(hdc,20,120,"NOMBRE DE APLICACIÓN",20);
        TextOut(hdc,230,120,"DESCRIPCIÓN",11);
        TextOut(hdc,20,180,"DIRECCIÓN URL",13);
        TextOut(hdc,20,300,"NOMBRE DE APLICACIÓN",20);
        TextOut(hdc,230,322,"PARAMETRO POSICIÓN:",19);
        TextOut(hdc,20,360,"NUEVO DATO",10);
        TextOut(hdc,20,480,"NOMBRE DE APLICACIÓN",20);



        TextOut(hdc,480,82,"NOMBRE APLIC:",13);
        TextOut(hdc,480,120,"USUARIO",7);
        TextOut(hdc,480,180,"CONTRASEÑA",10);
        TextOut(hdc,480,240,"CORREO DE CREACIÓN",18);
        TextOut(hdc,480,294,"C.V.USER:",9);
        TextOut(hdc,480,324,"C.V.PASS:",9);
        TextOut(hdc,480,360,"DNI",3);
        TextOut(hdc,560,360,"N.CEL 1",7);
        TextOut(hdc,644,360,"N.CEL 2",7);
        TextOut(hdc,729,360,"PREGUNTA VALIDACIÓN",19);
        TextOut(hdc,480,420,"NÚMERO DE TARGETA",17);
        TextOut(hdc,690,420,"NÚMERO DE CUENTA",16);
        TextOut(hdc,480,480,"CONTRASEÑA VIRTUAL",18);
        TextOut(hdc,724,503,"VCC:",4);
        TextOut(hdc,789,503,"CADUCA:",7);


        TextOut(hdc,945,120,"NOMBRE DE APLICACIÓN",20);
        TextOut(hdc,945,203,"NUMERO DE CUENTA:",17);
        TextOut(hdc,1160,203,"PARAMETRO:",10);
        TextOut(hdc,945,240,"NUEVO DATO",10);
        TextOut(hdc,945,360,"NOMBRE DE APLICACIÓN",20);
        TextOut(hdc,1244,360,"N.CT.",5);


        actual = SetTextColor(hdc, RGB(255,0,0));
        TextOut(hdc,20,17,"ESTADO:",7);
        TextOut(hdc,140,70,"PERFIL DE APLICACIONES",23);
        TextOut(hdc,620,17,"PERFIL DE CUENTAS",17);
        TextOut(hdc,960,40,"MODIFICAR Y EDITAR CUENTAS",26);

        SetTextColor(hdc, actual);
        DeleteObject(brushWhite);
        DeleteObject(greenPen);
}


BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch(uMsg)
    {
    case WM_PAINT:
        {   HDC hdc;
            PAINTSTRUCT ps;
            hdc=BeginPaint(hwndDlg,&ps);

            VISUAL_DESING(hdc);

            EndPaint(hwndDlg,&ps);
        }
        case WM_INITDIALOG:
        {
            if(UNA_VEZ){UNA_VEZ=0;
                system("color f0");
                cout<<"DESENCRIPTANDO DATOS...";
                DATOS_DE_ENCRIPTADO();
                LEER_DATOS();
                system("cls");
            }
        }
        return TRUE;

        case WM_CLOSE:
        {   EndDialog(hwndDlg, 0);
        }
        return TRUE;

        case WM_COMMAND:
        {   switch(LOWORD(wParam))
            {
                char C1[35],C2[35],C3[65],C4[65],C5[65],C6[65],C7[65],C8[65],
                     C9[65],C10[65],C11[65],C12[65],C13[65],C14[65],C15[65];
                int  N1,N2;


                case G_BTN_PRINTF_CMD_1:

                    A.MOSTRAR_CMD(1);

                    return TRUE;
                case G_BTN_PRINTF_CMD_2:

                    A.MOSTRAR_CMD(0);

                    return TRUE;

                case AP_BTN_C:

                    GetDlgItemText(hwndDlg,AP_EDIT_C1,C1,35);
                    GetDlgItemText(hwndDlg,AP_EDIT_C2,C2,35);
                    GetDlgItemText(hwndDlg,AP_EDIT_C3,C3,65);

                    if(V_CHAR(C1)&&V_CHAR(C2)&&V_CHAR(C3)){///COMPROBAR CARACTERES

                        if(C1[0]!='\0'&&C3[0]!='\0'){ ///CAMPOS REQUERIDOS

                            if(A.INSERTAR(C1,C2,C3)){///RETORNA VALIDACION

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"LOS DATOS SE INGRESARÓN CORRECTAMENTE");
                                SetDlgItemText(hwndDlg,AP_EDIT_C1,"");
                                SetDlgItemText(hwndDlg,AP_EDIT_C2,"");
                                SetDlgItemText(hwndDlg,AP_EDIT_C3,"");

                            }else{

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"LOS DATOS YA EXISTEN");

                            }

                        }else{

                            SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"FALTA ALGUNOS CAMPOS");

                        }

                    }else{

                        SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"CARACTER NO VALIDO");
                    }

                    return TRUE;

                case AP_BTN_M:

                    GetDlgItemText(hwndDlg,AP_EDIT_M1,C1,65);
                    GetDlgItemText(hwndDlg,AP_EDIT_M2,C2,65);
                    GetDlgItemText(hwndDlg,AP_EDIT_M3,C3,65);

                    N1 = atoi(C2);

                    if(V_CHAR(C1)&&V_CHAR(C3)){///COMPROBAR CARACTERES

                        if(C1[0]!='\0'&&C3[0]!='\0'&&N1>=0&&N1<3){ ///CAMPOS REQUERIDOS


                            if(A.BUSCARYMODIFICAR_VALOR(0,C1,N1,C3)){///RETORNA VALIDACION

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"LOS DATOS SE MODIFICARÓN CORRECTAMENTE");
                                SetDlgItemText(hwndDlg,AP_EDIT_M1,"");
                                SetDlgItemText(hwndDlg,AP_EDIT_M2,"");
                                SetDlgItemText(hwndDlg,AP_EDIT_M3,"");

                            }else{

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"ERROR!");

                            }

                        }else{

                            SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"FALTA ALGUNOS CAMPOS O POSISION INEXISTENTE");

                        }

                    }else{

                        SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"CARACTER NO VALIDO");
                    }

                    return TRUE;

                case AP_BTN_E:

                    GetDlgItemText(hwndDlg,AP_EDIT_E1,C1,65);

                    if(V_CHAR(C1)){///COMPROBAR CARACTERES

                        if(C1[0]!='\0'){ ///CAMPOS REQUERIDOS


                            if(A.ELIMINAR_APP(MAYUSCULAS(C1))){///RETORNA VALIDACION

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"EL DATO SE ELIMINÓ CORRECTAMENTE");
                                SetDlgItemText(hwndDlg,AP_EDIT_E1,"");

                            }else{

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"ERROR!");

                            }

                        }else{

                            SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"FALTA ALGUNOS CAMPOS O POSISION INEXISTENTE");

                        }

                    }else{

                        SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"CARACTER NO VALIDO");
                    }

                    return TRUE;

                case CNT_BTN_C:

                    GetDlgItemText(hwndDlg,CNT_EDIT_C1,C1,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C2,C2,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C3,C3,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C4,C4,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C5,C5,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C6,C6,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C7,C7,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C8,C8,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C9,C9,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C10,C10,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C11,C11,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C12,C12,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C13,C13,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C14,C14,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_C15,C15,65);

                    if(V_CHAR(C1)&&V_CHAR(C2)&&V_CHAR(C3)&&V_CHAR(C4)&&V_CHAR(C5)&&V_CHAR(C6)&&V_CHAR(C7)&&V_CHAR(C8)&&V_CHAR(C9)&&V_CHAR(C10)&&V_CHAR(C11)&&V_CHAR(C12)&&V_CHAR(C13)&&V_CHAR(C14)&&V_CHAR(C15)){///COMPROBAR CARACTERES

                        if(C1[0]!='\0'&&C2[0]!='\0'&&C3[0]!='\0'){ ///CAMPOS REQUERIDOS

                            if(A.BUSCARYMODIFICAR_VALOR(1,C1,0,"",C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13,C14,C15)){///RETORNA VALIDACION

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"LOS DATOS SE INGRESARÓN CORRECTAMENTE");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C1,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C2,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C3,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C4,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C5,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C6,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C7,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C8,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C9,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C10,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C11,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C12,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C13,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C14,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_C15,"");

                            }else{

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"ERROR! NO EXISTE APLICACIÓN");

                            }

                        }else{

                            SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"FALTA ALGUNOS CAMPOS");

                        }

                    }else{

                        SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"CARACTER NO VALIDO");
                    }


                    return TRUE;

                case CNT_BTN_M:

                    GetDlgItemText(hwndDlg,CNT_EDIT_M1,C1,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_M2,C2,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_M3,C3,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_M4,C4,65);

                    N1 = atoi(C2);
                    N2 = atoi(C3);

                    if(V_CHAR(C1)&&V_CHAR(C4)){///COMPROBAR CARACTERES

                        if(C1[0]!='\0'&&C4[0]!='\0'&&N2>=0&&N2<15){ ///CAMPOS REQUERIDOS

                            if(A.MODIFICAR_DATOS_CUENTA_SEC(C1,0,N1,N2,C4)){///RETORNA VALIDACION

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"LOS DATOS SE MODIFICARÓN CORRECTAMENTE");
                                SetDlgItemText(hwndDlg,CNT_EDIT_M1,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_M2,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_M3,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_M4,"");

                            }else{

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"ERROR! LA CUENTA Ó LA APP NO EXISTE");

                            }

                        }else{

                            SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"FALTA ALGUNOS CAMPOS O POSISION INEXISTENTE");

                        }

                    }else{

                        SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"CARACTER NO VALIDO");
                    }

                    return TRUE;

                case CNT_BTN_E:

                    GetDlgItemText(hwndDlg,CNT_EDIT_E1,C1,65);
                    GetDlgItemText(hwndDlg,CNT_EDIT_E2,C2,65);

                    N1 = atoi(C2);

                    if(V_CHAR(C1)){///COMPROBAR CARACTERES

                        if(C1[0]!='\0'&&N1>0){ ///CAMPOS REQUERIDOS

                            if(A.MODIFICAR_DATOS_CUENTA_SEC(C1,1,N1)){///RETORNA VALIDACION

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"LOS DATOS SE ELIMINARÓN CORRECTAMENTE");
                                SetDlgItemText(hwndDlg,CNT_EDIT_E1,"");
                                SetDlgItemText(hwndDlg,CNT_EDIT_E2,"");

                            }else{

                                SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"ERROR!");

                            }

                        }else{

                            SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"FALTA ALGUNOS CAMPOS O POSISION INEXISTENTE");

                        }

                    }else{

                        SetDlgItemText(hwndDlg,G_EDIT_ESTADO,"CARACTER NO VALIDO");
                    }

                    return TRUE;
            }
        }
        return TRUE;
        }
    return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
