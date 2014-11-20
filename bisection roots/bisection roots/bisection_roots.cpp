#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


double computeY(vector<float> coeffi_v, float X){
	int length = coeffi_v.size();
	double value = 0.0;

	for (int i = 0; i < length; i++)
	{
		value += coeffi_v[i] * pow(X, length - i - 1);
	}

	return value;
}



bool bisection_roots(vector<float> coeffi_v, float high_f, float low_f, float &root_f){
	float mid_f;
	double valueL_lf;     //high_f -> right_f ,low_f -> left_f
	double valueR_lf;
	double valueM_lf;

	valueL_lf = computeY(coeffi_v, low_f);
	valueR_lf = computeY(coeffi_v, high_f);

	if (valueR_lf * valueL_lf > 0) return false;

	while (true){
		mid_f = (high_f + low_f) / 2.0f;
		valueM_lf = computeY(coeffi_v, mid_f);
		if (abs(valueM_lf) < 0.00005)
		{
			root_f = mid_f;
			//printf("%lf\n",valueM_lf);
			return true;
		}

		if (valueM_lf * valueL_lf < 0.0){
			high_f = mid_f;
		}
		else low_f = mid_f;
	}

	return false;
}

int main(){
	int numcoeffi = 0;
	vector<float> coeffi_v; //ϵ����Ӧ��ָ���ɸߵ���
	float high_f = 0.0;
	float low_f = 0.0;
	float root_lf = 0.0;

	printf("��������ߴ���\n");
	scanf_s("%d", &numcoeffi);

	printf("������ϵ�����ߴ�ϵ��->�ʹ�ϵ��\n");
	for (int i = 0; i < numcoeffi + 1; i++){
		float tmp_f = 0.0;
		scanf_s("%f", &tmp_f);
		coeffi_v.push_back(tmp_f);
	}

	printf("�������������(С�߽� ��߽�)\n");
	while (scanf_s("%f %f", &low_f, &high_f) != EOF)
	{
		bool flag = bisection_roots(coeffi_v, high_f, low_f, root_lf);
		if (flag == true) printf("������[%f,%f]֮���һ������%f\n",low_f, high_f, root_lf);
		else printf("������[%f,%f]֮���޷��жϸ���λ��\n");
	}

	coeffi_v.clear();

	return 0;
}






