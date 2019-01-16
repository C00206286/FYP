/*
 *  Uzebox Default Patches
 *  Copyright (C) 2008  Alec Bourque
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
	Patches are made of a command stream made of 3 bytes per command:
		1=delta time
		2=command
		3=command parameter

	Patches must start with 1 byte describing the sound type:
		0=wave channel (i.e.; channel 0,1 and 2)
		1=noise channel (channel 3)
		2=PCM (channel 3)
		->For type=2 two more byte follows in order: sample adress low byte, sample adress hi byte

	It must end with <0,PATCH_END> and this command takes
	only two bytes (no parameter).
*/

  //INST: lead fast env       Channel 1....
  const char patch00[] PROGMEM ={ 
  0,PC_WAVE,4,
  0,PC_ENV_SPEED,-35,
  0,PATCH_END
  };
  //INST: lead slow env       Channel 2....
  const char patch01[] PROGMEM ={ 
  0,PC_WAVE,6,
  0,PC_ENV_VOL,0x40,
  0,PC_ENV_SPEED,-10,
  0,PATCH_END
  };
  //INST: bass -  triangular  Channel 3...
  const char patch02[] PROGMEM ={	
  0,PC_WAVE,2,
  1,PC_NOTE_HOLD,0,
  1,PC_ENV_SPEED,-32,
  0,PATCH_END
  };
  //INST: hi-hat              Channel 4...
  const char patch03[] PROGMEM ={	
  0,PC_NOISE_PARAMS,1,
  0,PC_ENV_VOL,0x90,
  0,PC_ENV_SPEED,-30, 
  8,PC_NOTE_CUT,0,
  0,PATCH_END
  }; 

const char fxjump[] PROGMEM = {
0,PC_WAVE,6,
0,PC_PITCH,50,
0,PC_ENV_VOL,0x70,
0,PC_ENV_SPEED,-4,
4,PC_NOTE_UP,1,
4,PC_NOTE_UP,1,
3,PC_NOTE_UP,1,
3,PC_NOTE_UP,1,
3,PC_NOTE_UP,1,
3,PC_NOTE_UP,1,
3,PC_NOTE_UP,1,
3,PC_NOTE_UP,1,
3,PC_NOTE_UP,1,
3,PC_NOTE_UP,1,
1,PC_NOTE_UP,1,
1,PC_NOTE_UP,1,
1,PC_NOTE_CUT,0,
0,PATCH_END 
};
const char fxhit[] PROGMEM = {
0,PC_WAVE,6,
0,PC_ENV_VOL,0x40,
0,PC_PITCH,40,
0,PC_ENV_SPEED,-16,   
0,PATCH_END
};
const char fxgameover1[] PROGMEM ={
0,PC_WAVE,4,
0,PC_ENV_SPEED,-4,
3,PC_PITCH,90,
3,PC_PITCH,96,
3,PC_PITCH,90,
3,PC_PITCH,96,
3,PC_PITCH,90,
1,PC_NOTE_CUT,0,
0,PATCH_END 
};



const char fxpoint[] PROGMEM = {
0,PC_WAVE,2,
0,PC_ENV_VOL,0x90,
2,PC_NOTE_UP,6,
2,PC_NOTE_UP,2,
1,PC_NOTE_UP,1,
0,PC_ENV_SPEED,-10,
0,PATCH_END
};

const char fxenemy[] PROGMEM = {
0,PC_ENV_VOL,0x80,
0,PC_WAVE,2,
0,PC_PITCH,64,
3,PC_NOTE_UP,4,
2,PC_NOTE_UP,4,
2,PC_NOTE_DOWN,8,
2,PC_NOTE_CUT,0,
0,PATCH_END
};
const char fxlivelost[] PROGMEM = {
0,PC_WAVE,1,
0,PC_ENV_VOL,0x80,
0,PC_ENV_SPEED,-3,
0,PC_PITCH,45,
5,PC_NOTE_DOWN,5, 
2,PC_NOTE_DOWN,1,
5,PC_NOTE_DOWN,5,  
2,PC_NOTE_DOWN,2,  
10,PC_NOTE_CUT,0,
0,PATCH_END 
};
const char fxlevelcompleted[] PROGMEM = {
0,PC_WAVE,3,
0,PC_ENV_VOL,0x80,
0,PC_PITCH,76,
2,PC_NOTE_DOWN,10, 
2,PC_NOTE_DOWN,8, 
2,PC_NOTE_DOWN,6, 
2,PC_NOTE_DOWN,4, 
2,PC_NOTE_DOWN,2, 
 
0,PC_PITCH,56, 
2,PC_NOTE_UP,5, 
2,PC_NOTE_DOWN,2, 
2,PC_NOTE_UP,5, 

2,PC_NOTE_UP,5, 
2,PC_NOTE_DOWN,2, 
2,PC_NOTE_UP,5,  

0,PC_ENV_SPEED,-8,   

4,PC_NOTE_UP,5, 
4,PC_NOTE_DOWN,5, 
4,PC_NOTE_UP,5, 
0,PATCH_END 
};

const struct PatchStruct patches[] PROGMEM = {
{0,NULL,patch01,0,0},
{0,NULL,patch01,0,0},
{0,NULL,patch01,0,0},
{0,NULL,patch01,0,0},
{0,NULL,fxjump,0,0},
{0,NULL,fxhit,0,0},
{0,NULL,fxgameover1,0,0},
{0,NULL,fxpoint,0,0},
{0,NULL,fxenemy,0,0},
{0,NULL,fxlivelost,0,0},
{0,NULL,fxlevelcompleted,0,0}
};
