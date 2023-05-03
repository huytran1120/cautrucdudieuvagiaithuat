#include <iostream>
using namespace std;
#define MAX 8
using namespace std;
class MaDiTuan
{
private:

	int Matrix[MAX][MAX] = { 0 };    //BAN ĐẦU KHỞI TẠO MẢNG 2 CHIỀU CÓ GIÁ TRỊ BẰNG 0
	int xMove[8] = { -2,-2,-1,-1, 1, 1, 2, 2 }; //TỌA ĐỘ X ĐC PHÂN TÍCH CHO MÃ
	int yMove[8] = { -1, 1,-2, 2,-2, 2,-1, 1 }; //TỌA ĐỘ Y ĐC PHÂN TÍCH CHO MÃ
    int COUNT = 0;  //SỐ BƯỚC MÃ DI CHUYỂN
	int N;          //SỐ PHẦN TỬ CỦA BÀN CỜ MUỐN TẠO CHO MỘT HÀNG HOẶC MỘT CỘT

public:

    //IN RA CÁC BƯỚC ĐI CỦA MÃ
	void PrintArray() {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << Matrix[i][j] << " ";
            cout << endl;
        }
	}

    //HÀM KIỂM TRA QUÂN MÃ NẰM TRONG BÀN CỜ 
    bool isSafe(int x, int y) {
        return x >= 0 && y >= 0 && x <= N - 1 && y <= N - 1 && Matrix[x][y] == 0;
    }

    void Move(int x, int y) {
        ++COUNT;        //TĂNG GIÁ TRỊ BƯỚC ĐI
        Matrix[x][y] = COUNT;//ĐÁNH DẤU ĐÃ ĐI QUA BƯỚC NÀY

            //VÒNG FOR ĐỂ TÌM TẤT CẢ CÁC BƯỚC ĐI PHÙ HỢP VÀ CÁC BƯỚC ĐI THỬ CHO NÓ
        for (int i = 0; i < 8; i++) {
            //KIỂM TRA XEM ĐÃ ĐI HẾT BÀN CỜ CHƯA
            if (COUNT == N * N) {
                cout << "Print steps: \n";
                PrintArray();
                exit(0);    //NẾU IN XONG THÌ KẾT THÚC CHƯƠNG TRÌNH
            }
            //NẾU CHƯA HẾT BÀN CỜ THÌ ĐI BƯỚC MỚI
            int u = x + xMove[i];   //MÃ SẼ ĐI BƯỚC MỚI TẠI VỊ TRÍ x MỚI
            int v = y + yMove[i];   //MÃ SẼ ĐI BƯỚC MỚI TẠI VỊ TRÍ y MỚI
            //KIỂM TRA TÍNH HỢP LỆ THÌ MÃ SẼ DI CHUYỂN
            if (isSafe(u,v) == true) 
                Move(u, v);
        }
        //NẾU KHÔNG TÌM THẤY BƯỚC ĐI NÀO PHÙ HỢP THÌ TRỎ LẠI VỊ TRÍ BAN ĐẦU
        --COUNT;
        Matrix[x][y] = 0;
    }

    void Enter()
    {
        cout << "Enter the number of steps : ";
        cin >> N;
        int a, b;
        cout << "Enter initial position.\nx: ";
        cin >> a;
        cout << "y: ";
        cin >> b;
        Move(a, b);
        //NẾU KHÔNG TÌM THẤY ĐƯỜNG ĐI THÌ THÔNG BÁO NHƯ SAU:
        cout << "Don't find !!";
    }
};

void main()
{
    MaDiTuan maDiTuan;
    maDiTuan.Enter();
}
