/*
    Copyright (C) 2019-Present SKALE Labs

    This file is part of sgxwallet.

    sgxwallet is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    sgxwallet is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with sgxwallet.  If not, see <https://www.gnu.org/licenses/>.

    @file domain_parameters.h
    @author Stan Kladko
    @date 2019
*/
#ifndef SGXWALLET_DOMAINPARAMETERS_H
#define SGXWALLET_DOMAINPARAMETERS_H


/*Type that represents a point*/
typedef struct point_s* point;
struct point_s
{
    mpz_t x;
    mpz_t y;
    bool infinity;
};


/*Type that represents a curve*/
typedef struct domain_parameters_s* domain_parameters;
struct domain_parameters_s
{
	char* name;
	mpz_t p;	//Prime
	mpz_t a;	//'a' parameter of the elliptic curve
	mpz_t b;	//'b' parameter of the elliptic curve
	point G;	//Generator point of the curve, also known as base point.
	mpz_t n;
	mpz_t h;
};

static inline point point_init();

/*Initialize a curve*/
static inline domain_parameters domain_parameters_init()
{
    domain_parameters curve;
    curve = calloc(sizeof(struct domain_parameters_s),1);

    //Initialize all members
    mpz_init(curve->p);
    mpz_init(curve->a);
    mpz_init(curve->b);
    curve->G = point_init();
    mpz_init(curve->n);
    mpz_init(curve->h);

    return curve;
}

/*Sets the name of a curve*/
static inline void domain_parameters_set_name(domain_parameters curve, char* name)
{
    int len = strlen(name);
    curve->name = (char*)calloc( sizeof(char) * (len+1), 1 );
    curve->name[len] = '\0';
    strncpy(curve->name, name, len+1);
}


static inline void point_set_ui(point p, unsigned long int x, unsigned long int y);

/*Set domain parameters from decimal unsigned long ints*/
static inline void domain_parameters_set_ui(domain_parameters curve,
                              char* name,
                              unsigned long int p,
                              unsigned long int a,
                              unsigned long int b,
                              unsigned long int Gx,
                              unsigned long int Gy,
                              unsigned long int n,
                              unsigned long int h)
{
    domain_parameters_set_name(curve, name);
    mpz_set_ui(curve->p, p);
    mpz_set_ui(curve->a, a);
    mpz_set_ui(curve->b, b);
    point_set_ui(curve->G, Gx, Gy);
    mpz_set_ui(curve->n, n);
    mpz_set_ui(curve->h, h);
}

static inline void point_set_hex(point p, char *x, char *y);

/*Set domain parameters from hexadecimal string*/
static inline void domain_parameters_set_hex(domain_parameters curve, char* name, char* p, char* a, char* b, char* Gx, char* Gy, char* n, char* h)
{
    domain_parameters_set_name(curve, name);
    mpz_set_str(curve->p, p, 16);
    mpz_set_str(curve->a, a, 16);
    mpz_set_str(curve->b, b, 16);
    point_set_hex(curve->G, Gx, Gy);
    mpz_set_str(curve->n, n, 16);
    mpz_set_str(curve->h, h, 16);
}


static inline void point_clear(point p);

/*Release memory*/
static inline void domain_parameters_clear(domain_parameters curve)
{
    mpz_clear(curve->p);
    mpz_clear(curve->a);
    mpz_clear(curve->b);
    point_clear(curve->G);
    mpz_clear(curve->n);
    mpz_clear(curve->h);
    free(curve->name);
    free(curve);
}


#endif