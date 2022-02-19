#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
string PARTIDO[5]={"La Gotita","La Casita","Poder Andino","Agua Cielo"};
class Mesa{
    int MMM=0,PPP=0;
    public:
    map<string,string>Mes;
    string DAT;
    int MAYOR,PARTID;
    void Insertar(string P, string Part1){
        Mes[P]=Part1;
    }
    string Valor(string P){
        return Mes[P];
    }
    int retmayor(){
        char *NUMTMP;
        int Candidatos[5];
        int mayor=0,cnD=0;
        NUMTMP=new char[10];
        for(int i=0,j=0,CAND=0;DAT[i];i++,j++){
            if(DAT[i]!=','){
                *(NUMTMP+j)=DAT[i];
                if(DAT[i+1]==','||DAT[i+1]==NULL){
                    *(NUMTMP+j+1)='\0';j=-2;
                    *(Candidatos+CAND) = atoi(NUMTMP);
                    delete(NUMTMP);CAND++;
                }
            }
        }
        for(int i=0;i<4;i++){
            if(mayor<*(Candidatos+i)){
                mayor=*(Candidatos+i);
                cnD=i;
            }
        }
        MAYOR=mayor;
        PARTID=cnD;
    }
    void Mostrar(){
        map<string, string>::iterator i;
        for(i=Mes.begin(); i!=Mes.end(); i++){
            DAT=(*i).second;
            retmayor();
            if(MMM<MAYOR){
                MMM=MAYOR;
                PPP=PARTID;
            }
            cout<<"\t\t\t\t- LUGAR DE VOTACION: ("<<(*i).first<<") , ("<<(*i).second<<")\n"
                <<"\t\t\t\t\tGANADOR: "<<PARTIDO[PARTID]<<" Con "<<MAYOR<<" Votos"<<endl;
        }
        cout<<endl;
    }
    int retMMM(){
        return MMM;
    }
    int retPPP(){
        return PPP;
    }
};
class Distritos{
    int MMM=0,PPP=0;
    public:
    map<string,Mesa> H;
    void Insertar(string Distr, string Mes, string Dat){
        map<string,Mesa>::iterator i=H.find(Distr);
        if(i!=H.end()){
            (i->second).Insertar(Mes,Dat);
        }
        else{
            Mesa dis;
            dis.Insertar(Mes,Dat);
            H[Distr]=dis;
        }
    }
    void Mostrar(){
        map<string,Mesa>::iterator i;
        cout<<"\t\t\t- DISTRITO: "<<endl;
        for(i=H.begin();i!=H.end();i++){
            cout<<"\t\t\t("<<(*i).first<<")"<<endl;
            ((*i).second).Mostrar();
            cout<<"\t\t\tGANADOR DISTRITAL: "<<PARTIDO[((*i).second).retPPP()]<<" Con "
                <<((*i).second).retMMM()<<" Votos\n\n";
            if(MMM<((*i).second).retMMM()){
                MMM=((*i).second).retMMM();
                PPP=((*i).second).retPPP();
            }
        }
    }
    int retMMM(){
        return MMM;
    }
    int retPPP(){
        return PPP;
    }
};
class provincia{
    int MMM=0,PPP=0;
    public:
    map<string,Distritos> H;
    void Insertar(string Prov, string Distr, string Mes, string DAT){
        map<string,Distritos>::iterator i=H.find(Prov);
        if(i!=H.end()){
            (i->second).Insertar(Distr,Mes,DAT);
        }
        else{
            Distritos prov;
            prov.Insertar(Distr,Mes,DAT);
            H[Prov]=prov;
        }
    }
    void Mostrar(){
        map<string,Distritos>::iterator i;
        cout<<"\t\t- PROVINCIA: "<<endl;
        for(i=H.begin();i!=H.end();i++){
            cout<<"\t\t("<<(*i).first<<")"<<endl;
            ((*i).second).Mostrar();
            cout<<"\t\tGANADOR PROVINCIAL: "<<PARTIDO[((*i).second).retPPP()]
                <<" Con "<<((*i).second).retMMM()<<" Votos\n\n";
            if(MMM<((*i).second).retMMM()){
                MMM=((*i).second).retMMM();
                PPP=((*i).second).retPPP();
            }
        }
    }
    int retMMM(){
        return MMM;
    }
    int retPPP(){
        return PPP;
    }
};
class departamento{
    int MMM=0,PPP=0;
    public:
    map<string,provincia> H;
    void Insertar(string Dep,string Prov, string Distr, string Mes,string DAT){
        map<string,provincia>::iterator i=H.find(Dep);
        if(i!=H.end()){
            (i->second).Insertar(Prov,Distr,Mes,DAT);
        }
        else{
            provincia dep;
            dep.Insertar(Prov,Distr,Mes,DAT);
            H[Dep]=dep;
        }
    }
    void Mostrar(){
        map<string,provincia>::iterator i;
        cout<<"\t- DEPARTAMENTO: "<<endl;
        for(i=H.begin();i!=H.end();i++){
            cout<<"\t("<<(*i).first<<")"<<endl;
            ((*i).second).Mostrar();
            cout<<"\tGANADOR DEPARTAMENTAL: "<<PARTIDO[((*i).second).retPPP()]
                <<" Con "<<((*i).second).retMMM()<<" Votos\n\n";
            if(MMM<((*i).second).retMMM()){
                MMM=((*i).second).retMMM();
                PPP=((*i).second).retPPP();
            }
        }
    }
    int retMMM(){
        return MMM;
    }
    int retPPP(){
        return PPP;
    }
};
class pais{
    public:
    map<string,departamento> H;
    void Insertar(string Pai,string Dep,string Prov, string Distr, string Mes,string DAT){
        map<string,departamento>::iterator i=H.find(Pai);
        if(i!=H.end()){
            (i->second).Insertar(Dep,Prov,Distr,Mes,DAT);
        }
        else{
            departamento pai;
            pai.Insertar(Dep,Prov,Distr,Mes,DAT);
            H[Pai]=pai;
        }
    }
    void Mostrar(){
        map<string,departamento>::iterator i;
        cout<<" - PAIS: "<<endl;
        for(i=H.begin();i!=H.end();i++){
            cout<<" ("<<(*i).first<<")"<<endl;
            ((*i).second).Mostrar();
            cout<<" GANADOR FINAL: "<<PARTIDO[((*i).second).retPPP()]
                <<" Con "<<((*i).second).retMMM()<<" Votos...\n\n";
        }
    }
};

int main(){
    pais H;
    /// 1 = la gotita, 2 = la casita, 3= poder andino, 4 = agua cielo
    ///        pais - depart-provin-distrit-sede de vot-partidos (1,2,3,4)
    H.Insertar("Peru","Puno","Puno","Coata","cocacola","345,232,33,534");
    H.Insertar("Peru","Puno","Puno","Coata","ekuisde","345,232,4554,534");
    H.Insertar("Peru","Puno","Puno","Puno","Glorioso","345,232,33,534");
    H.Insertar("Peru","Puno","Puno","Puno","Santa Rosa","345,8714,33,534");
    H.Insertar("Peru","Puno","Puno","Puno","Nro 45","345,4444,33,534");
    H.Insertar("Peru","Puno","Puno","Puno","San carlos","345,232,33,534");
    H.Insertar("Peru","Lima","Lima","Ate","30","345,232,33,445");
    H.Insertar("Peru","Lima","Lima","La Molina","las waifus","345,232,33,534");
    H.Insertar("Peru","Lima","Lima","La Molina","albedo","345,232,33,534");
    H.Insertar("Peru","Lima","Lima","La Molina","la mejor waifu","345,232,33,534");
    H.Insertar("Peru","Lima","Ate","La Morlina","meliodas","345,232,33,3232");
    H.Insertar("Peru","Lima","Ate","La Morlina","merlin","345,6765,232,534");
    H.Insertar("Peru","Lima","Ate","La Morlina","ban","6555,232,33,534");
    H.Insertar("Peru","Lima","Ate","La Morlina","king","345,232,33,534");
    H.Insertar("Peru","Lima","Ate","La Morlina","diane","345,87658,33,534");
    H.Insertar("Peru","Lima","Ate","La Morlina","escanor","345,8565,33,534");
    H.Insertar("Peru","Lima","Ate","La Morlina","gouwther","345,232,8565,534");
    H.Insertar("Peru","Lima","Ate","La Morlina","que wen momaso","4415,232,33,534");
    H.Insertar("Peru","Lima","Ate","La Morlina","te la creiste weee","345,232,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","no mames","345,2221,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","hola mundo","21,232,33,33");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","que hace","44,65,33,4433");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","equisddd","4344,232,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","intel","345,232,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","amd","345,34553,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","radeo","345,232,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","sli","345,232,5345,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","asus","345,232,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","gigabyte","345,34543,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","thermaltake","345,63334,33,534");
    H.Insertar("Peru","Arequipa","Arequipa","Arequipa","seaguet","345,232,77777,534");
    H.Insertar("Peru","Cusco","Cusco","Cusco","mia kalifa","345,232,92122,534");
    H.Insertar("Peru","Cusco","Cusco","Cusco","yordy","345,232,12,534");
    H.Insertar("Peru","Cusco","Cusco","Cusco","pelon de brazzers","345,232,3333,534");
    H.Insertar("Peru","Cusco","Cusco","Cusco","thanos","345,232,4423,534");
    H.Insertar("Peru","Cusco","Cusco","Cusco","tony","345,45444,5555,534");
    H.Insertar("Peru","Cusco","Cusco","Cusco","cap america","2342,232,886,534");
    H.Insertar("Peru","Cusco","Cusco","Cusco","thor","345,232,7869,534");
    H.Insertar("Peru","Cusco","Cusco","Cusco","kono subarashii","345,232,866,5414");
/*
    H.Insertar("Bolivia","La Paz","Los Andes","Pucarani","san jose","345,232,7544,534");
    H.Insertar("Bolivia","La Paz","Los Andes","Pucarani","yordy","345,546,33,534");
    H.Insertar("Bolivia","La Paz","Los Andes","Pucarani","mia kalifa","345,232,651,534");
    H.Insertar("Bolivia","La Paz","Los Andes","Pucarani","san miguel","98774,232,33,534");
    H.Insertar("Bolivia","La Paz","Los Andes","valle","san jose","44448,232,33,534");
    H.Insertar("Bolivia","La Paz","Los Andes","valle","yordy","345,5631,33,534");
    H.Insertar("Bolivia","La Paz","Los Andes","valle","mia kalifa","1112,232,651,534");
    H.Insertar("Bolivia","La Paz","Los Andes","valle","san miguel","22,232,33,534");
*/
    H.Mostrar();

    system("pause");
    return 0;
}
