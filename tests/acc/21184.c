#define царь_батюшка_голова() int main(int argc, char *argv[])
#define молвить printf
#define внемлить scanf
#define больше >
#define меньше <
#define коли if
#define отнюдь else
#define воздать return
#define для for

typedef int целина;
typedef long долговязый;

#include <stdio.h>

царь_батюшка_голова()
{
	целина н, бляха, к;
	внемлить("%d", &н);
	целина а[н];
	для (бляха = 0; бляха меньше н; бляха++) внемлить("%d", &а[бляха]);
		внемлить("%d", &к);
	долговязый совокупность = 0;
	для (бляха = 0; бляха меньше к; бляха++) совокупность += а[бляха];
	долговязый наибк = совокупность;
	для (бляха = к; бляха меньше н; бляха++) {
		совокупность = совокупность + а[бляха] - а[бляха - к];
		коли (совокупность больше наибк) наибк = совокупность;
	}
	молвить("%ld", наибк);
	воздать 0;
}