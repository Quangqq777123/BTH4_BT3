#include<iostream>
#include<cstring>
#define MAXARR 101
using namespace std;

void xuatChuoiKyTu(char str[], int n)
{
	
	for (int i = 0; i < n; i++) {
		cout << str[i];
	}
	cout << endl;
}

void xoaKhoangTrangDauvaCuoiChuoi(char str[],int &n) 
{	/*
	-Giả sử có 1 chuỗi:"   Chuoi ky    tu   "
	-Cần đưa về chuỗi có dạng:"Chuoi ky    tu"
	-Ý tưởng:
	+Loại bỏ khoảng trắng đầu chuỗi: kiểm tra xem tại vị trí đầu tiên
	của chuỗi ký tựu có phải là khoảng trắng hay không:
	* Nếu là khoảng trắng thì dời tất cả các ký tự trong chuỗi sang trái 1 đơn vị,
	  sau đó cập nhật lại độ dài của chuỗi.
	* Nếu không thì thoát vòng lặp

	+Loại bỏ khoảng trắng cuối chuỗi: kiểm tra tại vị trí cuối chuỗi có
	phải là khoảng trắng hay không:
	* Nếu có thì kiểm tra xem tại vị trí thứ n-1 có phải là khoảng trắng hay không:
		Nếu có thì giảm độ dài của chuỗi 1 đơn vị
		Nếu không thì thoát vòng lặp
	  
	* Nếu không thì thoát vòng lặp
	
	*/
	
	//Code Loại bỏ khoảng trắng đầu chuỗi

	while (isspace(str[0])&&n>=0) {
		for (int i = 0; i < n - 1; i++) {
			str[i] = str[i + 1];
		}
		n--;
	}
	//Loại bỏ khoảng trắng cuối chuỗi
	while ( isspace(str[n]) && n >= 0)
	{	
		if (!isspace(str[n - 1])) 
		{
			break;
		}
		else
		{
			n--; 
		}
	}

}

int demSoKhoangTrang(char str[], int n) {
	// Sử dụng hàm isspace() để duyệt qua các phần tử trong mảng
	// Nếu thỏa điều kiện thì tăng biến đếm 1 đơn vị
	int dem=0;
	for (int i = 0; i < n; i++) {
		if (isspace(str[i])) dem++;
	}

	return dem;
}

int demSoKyTuChuSohoacChuCai(char str[], int n) {
	// Sử dụng hàm isalpha() và hàm isalnum() để duyệt qua các phần tử trong mảng
	// Nếu thỏa điều kiện thì tăng biến đếm 1 đơn vị
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (isalpha(str[i])||isalnum(str[i])) dem++;
	}

	return dem;
}

int demSoKyTuInHoa(char str[], int n) {
	// Sử dụng hàm isupper() và hàm isalpha() để duyệt qua các phần tử trong mảng
	// Nếu thỏa điều kiện thì tăng biến đếm 1 đơn vị
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (isupper(str[i])&& isalpha(str[i])) dem++;
	}

	return dem;
}


int demSoKyTuInThuong(char str[], int n) {
	// Sử dụng hàm islower() và hàm isalpha() để duyệt qua các phần tử trong mảng
	// Nếu thỏa điều kiện thì tăng biến đếm 1 đơn vị
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (islower(str[i]) && isalpha(str[i])) dem++;
	}

	return dem;
}

void ChuyenChuoisangInHoa(char str[], int n) {
	/*
	-Sử dụng hàm islower() và hàm isalpha() để duyệt hết các phần tử trong mảng,
	nếu thỏa điều kiện thì sẽ đưa ký tự đó về dạng in hoa
	*/
	for (int i = 0; i < n; i++) {
		if (islower(str[i]) && isalpha(str[i])) {
			str[i] = char(int(str[i])-('a'-'A'));
		}
	}

}

void ChuyenChuoisangInThuong(char str[], int n) {
	/*
	-Sử dụng hàm isupper() và hàm isalpha() để duyệt hết các phần tử trong mảng,
	nếu thỏa điều kiện thì sẽ đưa ký tự đó về dạng in thường
	*/
	for (int i = 0; i < n; i++) {
		if (isupper(str[i]) && isalpha(str[i])) {
			str[i] = char(int(str[i]) + ('a' - 'A'));
		}
	}
}

void inHoaCacKyTuDauTienMoiTu(char str[], int n) {
	/*
	-Đầu tiên xét tại vị trí đầu tiên của chuỗi có phải là chữ cái được in hoa chưa
	+Nếu là chữ cái và chưa được in Hoa thì in Hoa ký tự đó lên
	+Nếu không phải là chứ cái hoặc là chữ cái đã được in hoa thì bỏ qua
	*/

	if (isalpha(str[0]) && islower(str[0]))
	{
		str[0] = char(int(str[0]) - ('a' - 'A'));
	}

	/*
	-Tiếp theo tiến hành duyệt từ vị trí 1 đến hết mảng ký tự, nếu tại vị trí thứ i là chữ cái chưa được in hoa và tại vị trí thứ i-1 là khoảng trắng 
	 thì tiến hành in hoa ký tự tại vị trí thứ i
	 -Lưu ý:  Cần phải đưa các ký tự chữ về in thường trước khi xét in hoa chữ cái đầu mỗi từ.
	*/
	for (int i = 1; i < n; i++) {
		if(isalpha(str[i])&&isupper(str[i])) str[i] = char(int(str[i]) + ('a' - 'A'));
		if(isalpha(str[i])&&islower(str[i])&&isspace(str[i-1])) str[i] = char(int(str[i]) - ('a' - 'A'));
	}
}

int demSoTuTrongChuoi(char str[], int n) {
	/*
	Ta xét ký tự đầu tiên trong chuỗi có phải là ký tự chữ cái hay số không
	+Nếu có thì gán đếm=1
	Nếu là khoảng trắng thì gán đếm =0
	*/
	int dem = 0;
	if (isalnum(str[0]) || isalpha(str[0])) dem = 1;
	/*
	-Tiếp theo tiến hành duyệt từ vị trí 1 đến hết mảng ký tự, nếu tại vị trí thứ i là chữ cái hoặc chữ số và tại vị trí thứ i-1 là khoảng trắng
	 thì tiến hành tăng biến đếm 1 đơn vị
	
	*/
	for (int i = 1; i < n; i++) {
		if(isspace(str[i-1])&&(isalpha(str[i])||isalnum(str[i]))) dem++;
	}

	return dem;
}
int main()
{
	char str[MAXARR];
	cout << "Nhap chuoi ky tu: ";
	cin.get(str, MAXARR);
	cin.ignore();
	int n = strlen(str);
	
	cout << "So tu trong chuoi la: " << demSoTuTrongChuoi(str, n) << endl;
	bool flag=false;
	for (int i = 0; i < n; i++) {
		if (!isspace(str[i])) {
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << "Chuoi khoang trang" << endl;
		return 0;
	}


	xoaKhoangTrangDauvaCuoiChuoi(str, n);
	xuatChuoiKyTu(str, n);

	cout << "So khoang trang trong chuoi la: "<<demSoKhoangTrang(str,n)<<endl;

	cout << "So ky tu la chu so hoac chu cai trong chuoi la: " << demSoKyTuChuSohoacChuCai(str, n) << endl;

	cout << "So ky tu in hoa trong chuoi la: " << demSoKyTuInHoa(str, n) << endl;

	cout << "So ky tu in thuong trong chuoi la: " << demSoKyTuInThuong(str, n) << endl;

	ChuyenChuoisangInHoa(str, n);
	cout << "Chuoi sau khi in hoa la: ";
	xuatChuoiKyTu(str, n);

	ChuyenChuoisangInThuong(str, n);
	cout << "Chuoi sau khi in thuong la: ";
	xuatChuoiKyTu(str, n);

	inHoaCacKyTuDauTienMoiTu(str, n);
	cout << "Chuoi sau khi hoa cac ky tu dau tien cua moi tu la: ";
	xuatChuoiKyTu(str, n);

	cout << "So tu trong chuoi la: " << demSoTuTrongChuoi(str, n)<<endl;
	return 0;
}