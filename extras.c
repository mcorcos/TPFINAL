/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

joy_init();										//inicializa el joystick
	disp_init();									//inicializa el display
	disp_clear();									//limpia todo el display
	dcoord_t pos = {7, 0};	//pos es la posición actual, empieza en el centro de la matriz
	dcoord_t npos = pos;							//npos es la próxima posición
	jcoord_t coord = {0,0};							//coordenadas medidas del joystick
	do
	{
            usleep(200000);
		printf(CYAN_TEXT "Joystick: (%4d,%4d)" , coord.x, coord.y);	//Imprime las coordenadas del joystick
		printf(WHITE_TEXT " | ");
		printf(RED_TEXT "Display: (%2d,%2d)\n" , npos.x, npos.y);	//Imprime la posición del LED encendio
		
		disp_update();	//Actualiza el display con el contenido del buffer
		joy_update();	//Mide las coordenadas del joystick
		coord = joy_get_coord();	//Guarda las coordenadas medidas
		
		//Establece la próxima posición según las coordenadas medidas
		if(coord.x > THRESHOLD && npos.x < DISP_MAX_X)
		{
			npos.x++;
		}
		if(coord.x < -THRESHOLD && npos.x > DISP_MIN)
		{
			npos.x--;
		}
                
                if(npos.y+(PIEZA_0.size)==15){
                    
                    
                    
                    (npos.y)=0;
                }
                else{
                    npos.y++;
                    
                }
                
		block_update(npos,pos);
		pos = npos;				//actualiza la posición actual
		
	} while( joy_get_switch() == J_NOPRESS );	//termina si se presiona el switch
    ;	//enciende la posición nueva en el buffer
		pos = npos;		
}

void block_update(dcoord_t npos,dcoord_t pos){
    
    int i,j;
    for(i=pos.x;i<((PIEZA_0.size)+pos.x);i++){
        
        for(j=pos.y;j<((PIEZA_0.size)+pos.y);j++){
            
            dcoord_t printpos;
            printpos.x=i;
            printpos.y=j;
            
            
            disp_write(printpos,D_OFF);
          
            
            
        };
    };
    
    for(i=npos.x;i<((PIEZA_0.size)+npos.x);i++){
        
        for(j=npos.y;j<((PIEZA_0.size)+npos.y);j++){
            	
            	
            dcoord_t printpos;
            printpos.x=i;
            printpos.y=j;
            
            if(PIEZA_0.values[(PIEZA_0.size)*(j-npos.y)+(i-npos.x)]==0 ){
            disp_write(printpos,D_OFF);
            }
            else{
                disp_write(printpos,D_ON);
            }
     
     
     
            
            
        };
    };
}