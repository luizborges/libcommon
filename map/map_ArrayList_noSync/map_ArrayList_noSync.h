/**
 */
#ifndef MAP_ARRAYLIST_NOSYNC_H
#define MAP_ARRAYLIST_NOSYNC_H

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <headers/memoryManager.h>
#include <headers/error.h>
#include <headers/arrayList_noSync.h>
#include <headers/map.h>

////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Structs
////////////////////////////////////////////////////////////////////////////////
typedef struct {
  char *key;
  void *content;
} Map_ArrayList_noSync_cell_o;

typedef struct {
  ArrayList_noSync_t list;
  Map_ArrayList_noSync_cell_o *lastAccessed; // guarda a referência para a última chave acessada (tanto para get, set, hasKey - é criado com o valor NULL - quando se deleta uma chave, essa variável é reinicializada para evitar bugs
  int lastAccessed_arrayIdx; // necessário guardar a posição(idx) que a chave fica no array, para o caso de deletar ela, para a otimização funcionar
} Map_ArrayList_noSync_o;

////////////////////////////////////////////////////////////////////////////////
// Typedefs
////////////////////////////////////////////////////////////////////////////////
typedef Map_ArrayList_noSync_cell_o* Map_ArrayList_noSync_cell_t;
typedef Map_ArrayList_noSync_o* Map_ArrayList_noSync_t;

////////////////////////////////////////////////////////////////////////////////
// Constructs
////////////////////////////////////////////////////////////////////////////////
extern Map_ArrayList_noSync_t Map_ArrayList_noSync_New();

extern map_t Map_ArrayList_noSync_New_Interface();

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

extern void  *Map_ArrayList_noSyncget (const void *_map, const char *key);
extern void  *Map_ArrayList_noSyncset (void *_map, const char *key, const void *content);
extern void  *Map_ArrayList_noSyncdel (void *_map, const char *key);
extern char **Map_ArrayList_noSynckey (const void *_map, int *numKeys); // numKeys = número de chaves existentes no map
extern bool   Map_ArrayList_noSynchasKey (const void *_map, const char *key);
extern void   Map_ArrayList_noSyncclean  (void *_map);
extern void   Map_ArrayList_noSyncend    (void *_map);

#ifdef __cplusplus
}
#endif
#endif // MAP_ARRAYLIST_NOSYNC_H

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////





