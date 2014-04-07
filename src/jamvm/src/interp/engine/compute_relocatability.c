/*
 * Copyright (C) 2003, 2004, 2005, 2006, 2007, 2008
 * Robert Lougher <rob@jamvm.org.uk>.
 *
 * This file is part of JamVM.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <stdio.h>

#include "jam.h"
#include "inlining.h"

int handler_sizes[HANDLERS][LABELS_SIZE];
int inlining_inited = FALSE;
int goto_len;

char *value2Str(int value, char *buff) {
    switch(value) {
        case MEMCMP_FAILED:
            return "MEMCMP_FAILED";
        case END_REORDERED:
            return "END_REORDERED";
        case END_BEFORE_ENTRY:
            return "END_BEFORE_ENTRY";

        default:
            sprintf(buff, "%d", value);
            return buff;
    }
}
  
int writeIncludeFile() {
    char buff[256];
    FILE *fd;
    int i, j;

    fd = fopen("relocatability.inc", "w");

    if(fd == NULL) {
        printf("ERROR : cannot write relocatability.inc (check permissions).\n");
        return 1;
    }

    fprintf(fd, "static int goto_len = %s;\n", value2Str(goto_len, buff));
    fprintf(fd, "static int handler_sizes[%d][%d] = {\n", HANDLERS, LABELS_SIZE);

    for(i = 0; i < HANDLERS; i++) {
        if(i > 0)
            fprintf(fd, ",\n");
        fprintf(fd, "    {\n");

        for(j = 0; j < LABELS_SIZE - 1; j++)
            fprintf(fd, "        %s,\n", value2Str(handler_sizes[i][j], buff));

        fprintf(fd, "        %s\n    }", value2Str(handler_sizes[i][LABELS_SIZE-1], buff));
    }

    fprintf(fd, "\n};\n");
    fclose(fd);

    return 0;
}

int main() {
    goto_len = calculateRelocatability(handler_sizes);
    return writeIncludeFile();
}


/* Stubs for functions called from executeJava */

Object *allocObject(pClass class) {
    return NULL;
}

Object *allocArray(pClass class, int size, int el_size) {
    return NULL;
}

Object *allocTypeArray(int type, int size) {
    return NULL;
}

Object *allocMultiArray(pClass array_class, int dim, intptr_t *count) {
    return NULL;
}

void *sysMalloc(int n) {
    return NULL;
}

pClass findArrayClassFromClassLoader(char *name, pObject loader) {
    return NULL;
}

pClass resolveClass(pClass class, int index, int init) {
    return NULL;
}

MethodBlock *resolveMethod(pClass class, int index) {
    return NULL;
}

MethodBlock *resolveInterfaceMethod(pClass class, int index) {
    return NULL;
}

FieldBlock *resolveField(pClass class, int index) {
    return NULL;
}

uintptr_t resolveSingleConstant(pClass class, int index) {
    return 0;
}

char isInstanceOf(pClass class, pClass test) {
    return 0;
}

char arrayStoreCheck(pClass class, pClass test) {
    return 0;
}

void signalChainedExceptionName(char *excep_name, char *excep_mess, pObject cause) {
}

void signalChainedExceptionEnum(int excep_enum, char *excep_mess, pObject cause) {
}

CodePntr findCatchBlock(pClass exception) {
    return NULL;
}

ExecEnv *getExecEnv() {
    return NULL;
}

void exitVM(int status) {
}

void jam_fprintf(FILE *stream, const char *fmt, ...) {
}

void initialiseDirect(InitArgs *args) {
}

void prepare(MethodBlock *mb, const void ***handlers) {
}

void objectLock(pObject ob) {
}

void objectUnlock(pObject ob) {
}

void inlineBlockWrappedOpcode(Instruction *pc) {
}

void checkInliningQuickenedInstruction(Instruction *pc, MethodBlock *mb) {
}

void inlineProfiledBlock(Instruction *pc, MethodBlock *mb) {
}

void shutdownInlining() {
}

