# PHILOSOPHERS [MAC version]
This project runs a simulation of the classic philosopher's problem using multithreading.

Notes:
- All data that is shared/accessed in any way between threads/the main must be protected by a mutex. 
Use fsanitize=thread flag in Makefile to check for potential dataraces.
- YOu can check whether a philo has died either in the main after launching all philosopher threads or in another thread. 
If you try to have each philosopher check his own death in his route, there will be delays where he has not been able to check whilst waiting for mutexes to unlock.
- Check that no philosophers are dead before every print to ensure nothing is printed after the death of a philo.
- Must print out death with no more than 10ms delay, it should therefore be printed out by main/checking thread as soon as death detected. Test with ./philo 2 310 200 200 and check death occurs before 310ms to check this.

Useful videos:
1) https://www.youtube.com/watch?v=uA8X5zNOGw8
2) https://www.youtube.com/watch?v=It0OFCbbTJE
3) https://www.youtube.com/watch?v=9axu8CUvOKY

Bonus:
https://www.youtube.com/watch?v=ukM_zzrIeXs&pp=ugMICgJmchABGAE%3D
