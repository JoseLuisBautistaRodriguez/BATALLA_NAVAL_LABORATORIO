#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	
	int ia = 0, ib, ic = 0, i, j, k = 0, in = 0, inpc = 0, inus = 0, io, ip, ivara, ivarb, ixus, ixpc, iypc, iyus;
	char cx, cy; 
	
	int iarpc[11][11];	  // Sus valores son 34 a 44 en iarprint 
	int iarus[11][11];	  // Sus valores son 9 a 19 en iarprint
	int iargam[5][5];     // Lleva las estadisticas
	int iarprin[17][52]; // Son los valores que se han de imprimir en pantalla
	system("color 0A");
		
	for ( i = 0 ; i < 11 ; i++){//Este bloque genera los valores para los cuadrantes 0 a 9 de la pc
		ib = 47 + i;
		for( j = 0 ; j < 11 ; j++){
			
			iarpc[i][j] = ib;
			ib++;
			
		}

	}
	
	for( i = 0 ; i < 11 ; i++){ //Este bloque genera los valores para los cuadrantes 0 a 9 del usuario
		ib = 47 + i;
		for( j = 0 ; j < 11 ; j++){
			
			iarus[i][j] = ib;
			ib++;
			
		}

	}	
	
	for ( i = 0 ; i < 17 ; i++){ //Este bloque genera la matriz de la pc con valores en 219 en el fondo de la aplicacion
	
		for( j = 0; j < 52; j++)
		{
			
			iarprin[i][j] = 219 ;	
			
		} 
	
	} 
		
		
		
		
	while( ia < 2 ){ // Juego =========================================================================
		
	
		
 //-----------------------------------------------------------------------------------------
		
		
		printf("\n");
		srand(time(NULL));	
		
		for ( i = 1 ; i < 11 ; i++){ //Este bloque genera la matriz de la pc con valores en 0 para la pc
		
			for( j = 1 ; j < 11 ; j++){
			
				iarpc[i][j] = 177;
			
			}
		
		}
			
		for ( i = 1 ; i < 11 ; i++){ //Este bloque genera la matriz de la pc con valores en 0 para el usuario
		
			for( j = 1 ; j < 11 ; j++){
			
				iarus[i][j] = 177;
			
			}
		
		}
	
		for( i = 0 ; i < 10 ; i++){ // Bloque que genera las naves de la pc 
			

			ivara = rand()% 10;
			ivara += 1;
			ivarb = rand()% 10;
			ivarb += 1;
			
			if( iarpc[ivara][ivarb] == 111){
				
				i--;				
				
			}
			
			iarpc[ivara][ivarb] = 111 ;
			
		}
	
		printf("\n");	
		
		for( i = 1; i < 11 ; i++ ){  //Éste bloque se encarga de pedirle los valores al usuario de sus naves:
		
			system ("cls");
		
			printf("\n\n\t\tIngresa el valor de tu nave %d:", i);
					
					printf("\n\n\t\tValor en x: ");
					scanf("%d", &ixus);
					printf("\n\t\tValor en y: ");
					scanf("%d", &iyus);
					
					ixus += 1;
					iyus += 1; 
					
					if( ixus < 11 && iyus < 11 && ixus > 0 && iyus > 0 ){
						

						if (iarus[ixus][iyus] == 111){
							
							printf("\n\n\t\tEse lugar ya esta ocupado.\n\n");
							i--;
							system ("pause");
						}
						
						iarus[ixus][iyus] = 111 ;
						
					}else{
						
						printf("\n\n\tUno de los valores que haz ingresado no es valido.\n\n");
						i--;
						system ("pause");
					}

		}			

	
	   	do {  // Inicia el juego +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		   	system("cls");
		   	       	
			system("color 1F");
			printf("\n\n\t\tBatalla Naval\n\n");
       		
               ivara = 0;
               ivarb = 0;

               if ( k > 0){  // Tablero pc ******************************************************* Ataque!!!
               	
	    				if ( iarpc[ixus][iyus] == 177){
		    				
		    				printf("\n\t\t\t\tHaz fallado\n\n");
		    				iarpc[ixus][iyus] = 176; 
		    				
		    			}else if(  iarpc[ixus][iyus] == 111 ){
		    				
                        	printf("\t\t\t\t%c%c Le Haz dado. %c%c\n\n", 219, 219, 219, 219);
		    				system("color 70");
		    				iarpc[ixus][iyus] = 178; 		    				
		    				inus++;
		    	
		    			}
               	
               }	
			   for( i = 3; i < 14 ; i++ ){ // Tablero pc *******************************************************
			
		    		for( j = 35 ; j < 46 ; j++ ){
		    			
                        if ( iarpc[i-3][j-35] == 111 ){
                        	
                        	io = 177;
                        	
                        }else{
                        	
                        	io = iarpc[i-3][j-35];
                        	
                        }  	
						   iarprin[i][j] = io;
                           ivarb++;
                    }
                    ivara++;
               }
               
	    
		    
				for ( i = 3; i < 14 ; i++ ){ // tablero usuario ****************************************
				
		    		for ( j = 6 ; j < 17 ; j++ ){
                        
						   iarprin[i][j] = iarus[i-3][j-6];
                           ivarb++;
                    }
                    ivara++;
               }
               
               if( k > 0 ){
               	
               		ixpc = rand() % 10 ;
               		ixpc += 1 ;
					iypc = rand() % 10 ;
					iypc += 1 ;
					
				      if( iarus[ixpc][iypc] == 111 ){
                        	
                        	iarus[ixpc][iypc] = 178 ;
                        	printf("\t\t\t\t%c%c Te han golpeado %c%c\n\n", 219, 219, 219, 219);
                        	system("color 0C");
                        	inpc++;
                        	
                        }else{
                        	
                        	iarus[ixpc][iypc] = 176 ;
                        	printf("\t\t\t\tEl enemigo ha fallado.\n\n");
                        
						}
               	
               	
               }   
			   
				iarprin[3][5] = 88 ;
				iarprin[2][6] = 89 ;
				iarprin[3][34] = 88 ;
				iarprin[2][35] = 89 ;
			
			
			
			// Tablero de Juego
			if(ic > -1){
				
				for( i = 5 ; i < 12; i++ )
				{
				
					for( j = 22; j < 30 ; j++)
					{
					
						iarprin[i][j] = 32;
					
					}
				
				}
				
				iarprin[6][23] = 86 ;
				iarprin[6][24] = 73 ;
				iarprin[6][25] = 68 ;
				iarprin[6][26] = 65 ;
				iarprin[6][27] = 83 ;
				
				if( inpc == 0){
					
					iarprin[8][25] = 49 ;
					iarprin[8][26] = 48 ;					
				}else{
					
					iarprin[8][26] = 58 - inpc ;	
					
				}
				
				iarprin[10][25] = 86 ;
				iarprin[10][26] = 83 ;
				iarprin[10][23] = 48 + inus ;
				iarprin[10][28] = 48 + inpc ;
				
			}           
                
                ivara = 0;
                ivarb = 0;
			
				for( i= 0; i < 17 ; i++ ){
					
					for( j = 0; j < 52; j++){
						
						printf("%c", iarprin[i][j]);
						
					}
					
					printf("\n");
					
				}
			
				do {
					ip = 0;
					printf("\n\t\tIngresa un valor en x: ");
					scanf("%d", &ixus);
					printf("\t\tIngresa un valor en y: ");		
					scanf("%d", &iyus);
			
					ixus += 1;
					iyus += 1;
					
					if(ixus < 11 && ixus > -1 && iyus < 11 && iyus > -1){
						ip = 5;
					}else{
						printf("\n\tLos valores no son correctos.\n");
					}
					
				}while(ip < 3);

		    	k++; 
		    	if ( inpc == 10 ){
		    		
		    		in = 11 ; 
		    		
		    	}else if( inus == 10){
		    		
		    		in = 11;
		    	}

			} while( in < 11);	// Bloque de juego
		
		if ( inpc == 10 ){
			
			printf("\n\tTe han ganado.");
			
		}else if(inus == 10){
			
			printf("\n\tTenemos la victoria.");
			
		}
		
		ic++;
			
			printf("\n\n\t Continuar jugando:\n\t\tSi = 1, No = 2:  ");
			scanf("%d", &ia);		
	
		if (ia < 1 || ia > 2){  	// Menu del juego, se activa solo despues de la segunda partida:---------------------------
			printf("\n\tValor no valido.");
			k;
		}else if( ia == 2){
				
			break;
				
		}
		
	}
	
	printf("El juego termino");
	return 0;
}
