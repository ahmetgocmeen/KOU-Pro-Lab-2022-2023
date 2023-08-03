using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProLab2Proje1
{
    public static class Extensions
    {
        public static IEnumerable<T> Shuffle<T>(this IEnumerable<T> source, Random rnd)
        {
            var e = source.ToArray();
            for (var i = e.Length - 1; i >= 0; i--)
            {
                var swapIndex = rnd.Next(i + 1);
                yield return e[swapIndex];
                e[swapIndex] = e[i];
            }
        }
        public static NodeState OppositeWall(this NodeState orig)
        {
            return (NodeState)(((int)orig >> 2) | ((int)orig << 2)) & NodeState.Initial;
        }
    }
}
