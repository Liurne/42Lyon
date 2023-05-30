/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:20:30 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/30 15:24:47 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//penser au char spe : " ' * $ | <<
//si "" bien copier tout le  contenue
//si '%2 = 1 || "%2 = 1 planter (ne pas conter le contenue entre guillemet)
//<< si 0 mot apres planter (le mot peut etre une commande)
//retirer tout les espaces n'etant pas entre guillemet
