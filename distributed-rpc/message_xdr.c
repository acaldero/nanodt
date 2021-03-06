/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "message.h"

bool_t
xdr_get_res (XDR *xdrs, get_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->value))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_d_init_1_argument (XDR *xdrs, d_init_1_argument *objp)
{
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->N))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_d_set_1_argument (XDR *xdrs, d_set_1_argument *objp)
{
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->i))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->value))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_d_get_1_argument (XDR *xdrs, d_get_1_argument *objp)
{
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->i))
		 return FALSE;
	return TRUE;
}
