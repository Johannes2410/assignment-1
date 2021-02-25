#include <stdio.h>
#include <windows.h>   

void main()  
{

char lecteur[5] = "c:\\";      

DWORD Secteurs_Par_Cluster, Bytes_Par_Secteurs, Cluster_libre, Total_Cluster; 
DWORD espace_libre, espace_utilise, espace_total;   

bool ret=GetDiskFreeSpace(lecteur,&Secteurs_Par_Cluster,&Bytes_Par_Secteurs,&Cluster_libre,&Total_Cluster);

espace_utilise = ((Cluster_libre * Secteurs_Par_Cluster * Bytes_Par_Secteurs)/1024)/1024;
espace_total = (((Total_Cluster * Secteurs_Par_Cluster)/1024)*Bytes_Par_Secteurs)/1024;
espace_libre = espace_total - espace_utilise;

PRT_I (ret);
PRT_U (espace_libre);
