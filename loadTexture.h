#ifndef _LOAD_TEXTURE_H
#define _LOAD_TEXTURE_H

/**********************************************************
 *
 * FUNCTION LoadBitmap(char *p_filename)
 *
 * This function loads a bitmap file and return the OpenGL reference ID to use that texture
 *
 * Input parameters: p_filename = Filename of the bitmap to load
 *
 * Return value: (char) >-1 if the image was loaded correctly, -1 otherwise
 *
 *********************************************************/
extern int loadTexture( char* file_name); //load file bmp

#endif
