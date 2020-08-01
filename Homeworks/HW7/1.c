interleave() {
	
	pthread_t th0, th1;		// creating two threads th0, th1
	
	int count=0;

	pthread_create(&th0, 0, test, 0);		
	pthread_create(&th1, 0, test, 0);

	pthread_join(th0, 0);
	pthread_join(th1, 0);

	printf(count);

}


test() {
	for (int j=0; j<MAX; j++)
		count = count+1;
}