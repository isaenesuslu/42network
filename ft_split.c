/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:18:41 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:18:42 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**ft_check(char **wordlist, int i)
{
	int	j;

	j = i - 1;
	while (j >= 0)
	{
		if (wordlist[j] == NULL)
		{
			while (i >= 0)
			{
				free(wordlist[i]);
				i--;
			}
			free(wordlist);
			return (NULL);
		}
		j--;
	}
	return (wordlist);
}

static char	*ft_word_calculator(char const *s, char const *end)
{
	char	*word;
	char	*wordtemp;
	int		len;

	len = (end - s);
	word = (char *) malloc(len + 1);
	if (word)
	{
		wordtemp = word;
		while (s != end)
		{
			*wordtemp = *s;
			wordtemp++;
			s++;
		}
		*wordtemp = '\0';
		return (word);
	}
	return (NULL);
}

static char	**ft_wordlist(char const *s, char c, int counter)
{
	char		**wordlist;
	char const	*s_end;
	int			i;

	wordlist = (char **) malloc(sizeof(char *) * (counter + 1));
	s_end = s;
	i = 0;
	if (wordlist)
	{
		while (*s_end)
		{
			while (*s_end == c && *s_end)
				s_end++;
			if (*s_end)
			{
				s = s_end;
				while (*s_end != c && *s_end)
					s_end++;
				wordlist[i++] = ft_word_calculator(s, s_end);
			}
		}
		wordlist[i] = NULL;
		return (ft_check(wordlist, i));
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char const	*stemp;
	int			counter;

	if (s)
	{
		stemp = s;
		counter = 0;
		while (*stemp)
		{
			if (*stemp == c)
				stemp++;
			else
			{
				while (*stemp != c && *stemp)
					stemp++;
				counter++;
			}
		}
		return (ft_wordlist(s, c, counter));
	}
	return (NULL);
}
