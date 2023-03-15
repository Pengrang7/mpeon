#include <stdio.h>
#include "gps.h"

struct gps_data_t g_GpsData;

int main()
{
	printf("gps test main!!\n");

	int ret;
	ret = gps_open("localhost", DEFAULT_GPSD_PORT, &(g_GpsData));
	if(ret)
	{
	    printf("Fail to gps_open(): %d(reason: %s)\n", ret, gps_errstr(ret));
        return ret;
	}
	printf("Success to gps_open()\n");

	gps_stream(&g_GpsData, WATCH_ENABLE | WATCH_JSON, NULL);

	int cnt = 0;
	while(cnt < 10)
	{
		if(!gps_waiting(&g_GpsData, 1000*5000))
		{
			printf("gps waiting timeout!!!\n");
			continue;
		}
		
		int ret = gps_read(&g_GpsData, NULL, 0);
		if (ret < 0)
		{
			printf("Fail to gps_read() %d(reason: %s)\n", ret, gps_errstr(ret));

			break;
		}

		printf("GPS READ Fix[%d] Time[%ld]\n", g_GpsData.fix.mode, g_GpsData.fix.time.tv_sec);
		cnt++;
	}

	gps_stream(&g_GpsData, WATCH_DISABLE, NULL);
	gps_close(&g_GpsData);

	return 0;
}
