char p[80] = {};

//在工作流程中设置工率号
void ZHOU_1{
	power_num = 32;	//设置一号流程电机功率为32
	n_temp = power_num;	//将最初查询功率号设置为power_num，以减少查询时间
}

void power_static{
	power = BO * p[power_num];
	UAD_temp = UAD;
	power_now = UAD_temp * p[n_temp];
	if(power < power_now)
		n_temp++;
	else if(power > power_now)
		n_temp--;
	power_duty = n_temp;
}

int main(){
	power_static();
}

//也可以在定时中断中调用此函数
/*
void time0() interrupt 0
{
	power_static();
}
*/
