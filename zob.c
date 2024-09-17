int arr[3000];
int i = 0;

int main()
{
	arr[i]++;
	i++;
	i++;
	arr[i]++;
	i++;
	i++;
	arr[i]++;
	i--;
	i--;
	i--;
	i--;
	while ( arr[i] != 0 )
{
		printf("%d\n", arr[i]);
		i++;
		i++;
				i--;
				i++;
		i++;
		i++;
				i--;
				while ( arr[i] != 0 )
{
			arr[i]--;
			i--;
			i--;
			while ( arr[i] != 0 )
{
				arr[i]--;
				i--;
				arr[i]++;
				i++;
				}
			i++;
						i--;
						i++;
			i++;
			}
		i++;
		arr[i]++;
		i--;
		i--;
		i--;
		i--;
				i++;
		i++;
				i--;
		i--;
		}
}
