#include<stdio.h>
#include<conio.h>
void main()
{
	int yeu_cau[100][100];
	int tai_nguyen_hien_hanh[100][100];
	int yeu_cau_tai_nguyen[100][100];
	int tai_nguyen_san_co[100];
	int tien_trinh, tai_nguyen;
	int i, j;
	int finish[100], temp, flag = 1, k, c1 = 0;
	int tac_nghen[100];
	int trang_thai_an_toan[100];
	printf("\n************************************************************************************************");
	printf("\n*                                            NHOM 10                                           *");
	printf("\n*                                GIAI THUAT PHAT HIEN TAC NGHEN                                *");
	printf("\n************************************************************************************************\n");
	printf("nhap so tien trinh: ");
	scanf("%d", &tien_trinh);
	printf("\nnhap so loai tai nguyen cap phat: ");
	scanf("%d", &tai_nguyen);
	printf("\nnhap ma tran tai nguyen yeu cau hien tai (Request) cua moi tien trinh (moi tien trinh 1 dong)\n");
	for (i = 0; i<tien_trinh; i++)
	{
		for (j = 0; j<tai_nguyen; j++)
		{
			scanf("%d", &yeu_cau[i][j]);
		}
	}
	printf("\nnhap ma tran tai nguyen da cap phat (Allocation) (moi tien trinh 1 dong)\n");
	for (i = 0; i<tien_trinh; i++)
	{
		for (j = 0; j<tai_nguyen; j++)
		{
			scanf("%d", &tai_nguyen_hien_hanh[i][j]);
		}
	}
	printf("\nTai nguyen co san cua he thong (Available)\n");
	for (j = 0; j<tai_nguyen; j++)
	{
		scanf("%d", &tai_nguyen_san_co[j]);
	}
	printf("\tKET QUA GIAI THUAT PHAT HIEN TAC NGHEN\n");
	printf("\nTIEN TRINH\t Allocation\tRequest\t Available\t");
	for (i = 0; i<tien_trinh; i++)
	{
		printf("\nTien trinh P%d\t   ", i);
		for (j = 0; j<tai_nguyen; j++)
		{
			printf("%d ", tai_nguyen_hien_hanh[i][j]);
		}
		printf("\t");
		for (j = 0; j<tai_nguyen; j++)
		{
			printf("%d ", yeu_cau[i][j]);
		}
		printf("\t");
		if (i == 0)
		{
			for (j = 0; j<tai_nguyen; j++)
				printf(" %d ", tai_nguyen_san_co[j]);
		}
	}
	for (i = 0; i<tien_trinh; i++)
	{
		finish[i] = 0;
	}
	for (i = 0; i<tien_trinh; i++)
	{
		for (j = 0; j<tai_nguyen; j++)
		{
			yeu_cau_tai_nguyen[i][j] = yeu_cau[i][j];
		}
	}
	while (flag)
	{
		flag = 0;
		for (i = 0; i<tien_trinh; i++)
		{
			int c = 0;
			for (j = 0; j<tai_nguyen; j++)
			{
				if ((finish[i] == 0) && (yeu_cau_tai_nguyen[i][j] <= tai_nguyen_san_co[j]))
				{
					c++;
					if (c == tai_nguyen)
					{
						for (k = 0; k<tai_nguyen; k++)
						{
							tai_nguyen_san_co[k] += tai_nguyen_hien_hanh[i][j];
							finish[i] = 1;
							flag = 1;
						}
						if (finish[i] == 1)
						{
							i = tien_trinh;
						}
					}
				}
			}
		}
	}
	j = 0;
	flag = 0;
	for (i = 0; i<tien_trinh; i++)
	{
		if (finish[i] == 0)
		{
			tac_nghen[j] = i;
			j++;
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("\n\nHe thong bi tac nghen va tien trinh tac nghen:\n");
		for (i = 0; i<tien_trinh - 1; i++)
		{
			printf("P%d\t", tac_nghen[i]);
		}
	}
	else
	{
		printf("\n\n\tHe thong Khong bi tac nghen!!!");
	}
	getch();
}
