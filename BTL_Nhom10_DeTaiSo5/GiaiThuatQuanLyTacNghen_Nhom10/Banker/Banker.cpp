#include <stdio.h>
#include <conio.h>
void main()
{
	int dem = 0, m, n, tien_trinh, tam, tai_nguyen;
	int bang_tai_nguyen[5] = { 0, 0, 0, 0, 0 };
	int tai_nguyen_co_san[5], tai_nguyen_hien_hanh[5][5], yeu_cau_toi_da[5][5];
	int tai_nguyen_toi_da[5], dang_chay[5], trang_thai_an_toan = 0;
	printf("\n*************************************TRANH TAC NGHEN BANKER*************************************");
	printf("\n*                                           NHOM 10                                            *");
	printf("\n************************************************************************************************\n");
	printf("\nNhap so tien trinh: ");
	scanf("%d", &tien_trinh);
	for (m = 0; m < tien_trinh; m++)
	{
		dang_chay[m] = 1;
		dem++;
	}
	printf("\nNhap tong so loai tai nguyen cap phat: ");
	scanf("%d", &tai_nguyen);
	printf("\nNhap tong so tai nguyen moi loai: ");
	for (m = 0; m < tai_nguyen; m++)
	{
		scanf("%d", &tai_nguyen_toi_da[m]);
	}
	printf("\nNhap ma tran tai nguyen da cap phat (moi tien trinh 1 dong)\n");
	for (m = 0; m < tien_trinh; m++)
	{
		for (n = 0; n < tai_nguyen; n++)
		{
			scanf("%d", &tai_nguyen_hien_hanh[m][n]);
		}
	}
	printf("\nNhap ma tran tai nguyen yeu cau toi da cua cac tien trinh (moi tien trinh 1 dong)\n");
	for (m = 0; m < tien_trinh; m++)
	{
		for (n = 0; n < tai_nguyen; n++)
		{
			scanf("%d", &yeu_cau_toi_da[m][n]);
		}
	}
	printf("\tKET QUA GIAI THUAT BANKER\n");
	printf("\nTong moi loai tai nguyen cua he thong\n");
	for (m = 0; m < tai_nguyen; m++)
	{
		printf("\t%d", tai_nguyen_toi_da[m]);
	}
	printf("\nMa tran tai nguyen da cap phat\n");
	for (m = 0; m < tien_trinh; m++)
	{
		for (n = 0; n < tai_nguyen; n++)
		{
			printf("\t%d", tai_nguyen_hien_hanh[m][n]);
		}
		printf("\n");
	}
	printf("\nMa tran tai nguyen toi da ma cac tien trinh can dung\n");
	for (m = 0; m < tien_trinh; m++)
	{
		for (n = 0; n < tai_nguyen; n++)
		{
			printf("\t%d", yeu_cau_toi_da[m][n]);
		}
		printf("\n");
	}
	for (m = 0; m < tien_trinh; m++)
	{
		for (n = 0; n < tai_nguyen; n++)
		{
			bang_tai_nguyen[n] += tai_nguyen_hien_hanh[m][n];
		}
	}
	printf("\nTai nguyen da cap phat\n");
	for (m = 0; m < tai_nguyen; m++)
	{
		printf("\t%d", bang_tai_nguyen[m]);
	}
	for (m = 0; m < tai_nguyen; m++)
	{
		tai_nguyen_co_san[m] = tai_nguyen_toi_da[m] - bang_tai_nguyen[m];
	}
	printf("\nTai nguyen co san cua he thong\n");
	for (m = 0; m < tai_nguyen; m++)
	{
		printf("\t%d", tai_nguyen_co_san[m]);
	}
	printf("\n");
	printf("\nTIEN TRINH\t\tCHUOI AN TOAN\t\t TAI NGUYEN SAN CO\n");
	while (dem != 0)
	{
		trang_thai_an_toan = 0;
		for (m = 0; m < tien_trinh; m++)
		{
			if (dang_chay[m])
			{
				tam = 1;
				for (n = 0; n < tai_nguyen; n++)
				{
					if (yeu_cau_toi_da[m][n] - tai_nguyen_hien_hanh[m][n] > tai_nguyen_co_san[n])
					{
						tam = 0;
						break;
					}
				}
				if (tam)
				{
					printf("\nTIEN TRINH P%d\t", m);
					dang_chay[m] = 0;
					dem--;
					trang_thai_an_toan = 1;
					for (n = 0; n < tai_nguyen; n++)
					{
						tai_nguyen_co_san[n] += tai_nguyen_hien_hanh[m][n];
					}
					break;
				}
			}
		}
		if (!trang_thai_an_toan)
		{
			printf("\tTien trinh o trang thai khong an toan\n");
			break;
		}
		else
		{
			printf("\tTien trinh an toan");
			for (m = 0; m < tai_nguyen; m++)
			{
				printf("\t%d", tai_nguyen_co_san[m]);
			}
			printf("\n");
		}
	}
	getch();
}