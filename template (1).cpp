
#include <iostream>

using namespace std;
#include <cstring>

class CanBo{
    private:
        string HoTen;
        int Tuoi;
        string GioiTinh;
        string DiaChi;

};
class CongNhan:public CanBo{
    private:
        int Bac;
    public:
};
class KySu:public CanBo{
    private:
        string NganhDaoTao;
    public:

};
class NhanVien:public CanBo{
    private:

        string CongViec;
    public:
};
class QLCB{
    private:
        CanBo canbo[100];
        int cnt;
    public:
        void add(){
            int cnt;
            cout<<"Nhap so phan tu:"<<endl;
            cin>>cnt;

            for(int i=0;i<this->cnt;i++){
                cout<<"Nhap ten:"<<endl;
                getline(cin,this->canbo[i].HoTen);
                cin.ignore();
                cout<<"Nhap tuoi:"<<endl;
                cin>>this->canbo[i].Tuoi;
                cout<<"Nhap dia chi:"<<endl;
                getline(cin,this->canbo[i].DiaChi);
                cin.ignore();
                while(1){
                    cout<<"Nhap gioi tinh(Nam,Nu,Khac):"<<endl;
                    getline(cin,this->canbo[i].GioiTinh);
                    if(this->canbo[i].GioiTinh=='Nam','Nu','Khac')
                        break;
                }

            }
            this->cnt+=cnt;



        }
        void output(int i){
            cout<<"Ho ten:"<<this->canbo[i].HoTen<<endl;
            cout<<"Tuoi:"<<this->canbo[i].Tuoi<<endl;
            cout<<"Dia chi:"<<this->canbo[i].DiaChi<<endl;
            cout<<"Gioi tinh:"<<this->canbo[i].GioiTinh<<endl;
            }
        void outputAll(){
            for(int i=0;i<this->cnt;i++){
                if(this->canbo[i].Tuoi==0)
                    continue;
                cout<<"Can bo thu" <<i+1<<":"<<endl;
                this->output(i);

            }
        }
        void Search(){
            string tmp;
            int cnt=0;
            getline(cin,tmp);
            cin.ignore();
            for(int i=0;i<this->cnt;i++){
                if(tmp == this->canbo[i].HoTen){
                cout<<"Da tim thay."<<endl;
                output(i);
                break;
            }
            else
                ++cnt;
            }
            if(cnt==0)
                cout<<"Khong tim thay."<<endl;
            }

        void Del(){
            string tmp;
            int cnt=0;
            getline(cin,tmp);
            cin.ignore();
            for(int i=0;i<this->cnt;i++){
                if(tmp == q[i].HoTen){
                    this->canbo[i].HoTen=this->canbo[i].DiaChi=this->canbo[i].GioiTinh=NULL;
                    this->canbo[i].Tuoi = 0;

                    break;
            }
                else
                    ++cnt;
            }
            if(cnt==0)
                cout<<"Khong tim thay.";
        }





};
void menu(QLCB q){
    int n=0;
    while(1){
        cout<<"1.Them moi can bo."<<endl;
        cout<<"2.Tim kiem theo ho ten."<<endl;
        cout<<"3.Hien thi thong tin va danh sach can bo."<<endl;
        cout<<"4.Nhap vao ten can bo va xoa can bo do."<<endl;
        cout<<"5.Thoat khoi chuong trinh."<<endl;
        cout<<"Chon 1->5:"<<endl;
        cin>>n;
        switch(n){
        case 1:
            q.add();
            break;
        case 2:
            q.Search();
            break;
        case 3:
            q.outputAll();
            break;

        case 4:
            q.Del();
            break;
        case 5:
            break;


    }
    }
}
int main(){
    QLCB q;
    menu(q);
    return 0;
}
